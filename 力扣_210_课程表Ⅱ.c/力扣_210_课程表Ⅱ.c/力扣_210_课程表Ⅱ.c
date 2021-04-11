#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//�ڽӱ�ڵ�
struct adjNode {
    int arrnum;
    struct adjNode* next;
};
//�ڽӱ�
struct Node {
    int into;
    struct adjNode* next;
    struct adjNode* tmp;
};

//�����ڽӱ�
struct Node* CreateAdj(int size)
{
    struct Node* adj = (struct Node*)malloc(sizeof(struct Node) * size);
    assert(adj);

    //��ʼ��
    for (int i = 0; i < size; i++)
    {
        adj[i].into = 0;
        adj[i].next = NULL;
        adj[i].tmp = NULL;
    }

    return adj;
}

//�����ڽӱ�ڵ�
struct adjNode* CreateAdjNode(int arrnum)
{
    struct adjNode* newNode = (struct adjNode*)malloc(sizeof(struct adjNode));
    assert(newNode);
    
    //��ʼ��
    newNode->arrnum = arrnum;
    newNode->next = NULL;

    return newNode;
}

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    struct Node* adj = CreateAdj(numCourses);

    for (int i = 0; i < prerequisitesSize; i++)
    {
        //��ֹtmp��nextָ��ͬ�ط�
        if (adj[prerequisites[i][1]].tmp == NULL)
        {
            adj[prerequisites[i][0]].into++;
            struct adjNode* newNode = CreateAdjNode(prerequisites[i][0]);
            adj[prerequisites[i][1]].next = newNode;
            adj[prerequisites[i][1]].tmp = adj[prerequisites[i][1]].next;
        }
        else
        {
            adj[prerequisites[i][0]].into++;
            struct adjNode* newNode = CreateAdjNode(prerequisites[i][0]);
            adj[prerequisites[i][1]].tmp->next = newNode;
            adj[prerequisites[i][1]].tmp = adj[prerequisites[i][1]].tmp->next;
        }
    }

    //����ջ�ͽ������
    int* stack = (int*)malloc(sizeof(int) * numCourses);
    //int* stack = (int*)calloc(numCourses, sizeof(int));
    assert(stack);
    int* rst = (int*)malloc(sizeof(int) * numCourses);
    //int* rst = (int*)calloc(numCourses, sizeof(int));
    assert(rst);

    int count = 0;
    int sttmp = -1;
    int retmp = -1;

    //�Ѵ�ʱinto = 0�Ľڵ���ջ
    for (int i = 0; i < numCourses; i++)
    {
        if (adj[i].into == 0) { stack[++sttmp] = i; }
    }

    while (1)
    {
        if (sttmp != -1)
        {
            int k = stack[sttmp--];
            rst[++retmp] = k;
            //printf ("%d", k);

            struct adjNode* po = adj[k].next;

            while (po)
            {
                adj[po->arrnum].into--;
                if (adj[po->arrnum].into == 0) { stack[++sttmp] = po->arrnum; }
                po = po->next;
            }

            count++;
        }
        else { break; }
    }
    //printf ("%d %d", res[0], res[1]);
    //free(stack);
    //stack = NULL;
    printf("%d %d", count, numCourses);
    if (count < numCourses) { *returnSize = 0; }
    else { *returnSize = numCourses; }
    return rst;
}

/*********************************************************************************************************************************/

/*struct MyNode{
    int data;
    struct node* next;
};
struct Graph{
    struct MyNode* graph;
};
int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize){
    int* output=(int*)malloc(sizeof(int)*numCourses);
    int count=-1; //��¼pop���Ľ���� �������Ƚ��Ƿ��л�����(�����-1��ʼ �������������±�  �����Ƚϵ�ʱ��Ӧ+1)
    int* inDegree=(int*)malloc(sizeof(int)*numCourses);   //inDegree��¼�������
    memset(inDegree,0,sizeof(int)*numCourses);
    int* stack=(int*)malloc(sizeof(int)*numCourses);  //��ջ��������Ϊ0�Ľ��
    int top=-1;
    /*�����ڽӱ�*/
    /*struct Graph* G=(struct Graph*)malloc(sizeof(struct Graph));
    G->graph=(struct MyNode*)malloc(sizeof(struct MyNode)*numCourses);
    for(int i=0;i<numCourses;i++)
    {
        G->graph[i].data=0;
        G->graph[i].next=NULL;
    }
    for(int i=0;i<prerequisitesSize;i++)
    {
        struct MyNode* tempNode=(struct MyNode*)malloc(sizeof(struct MyNode)); //�����½�㣬����ͷ�巨�����ڽӱ���
        tempNode->data=prerequisites[i][0];
        tempNode->next=G->graph[ prerequisites[i][1] ].next;
        G->graph[ prerequisites[i][1] ].next=tempNode;
        inDegree[ prerequisites[i][0] ]++;   //��ָ����Ǹ������ȼ�һ
    }
    /*�ȱ���һ�����нڵ�  �����Ϊ��Ľ����ջ*/
    /*for(int i=0;i<numCourses;i++)
       if(inDegree[i]==0)
          stack[++top]=i;
    /*whileѭ����������*/
    /*while(top!=-1)
    {
        int tempV=stack[top--];
        output[++count]=tempV;
        struct MyNode* tempNode=G->graph[tempV].next;
        while(tempNode!=NULL)         //�����ڽӱ��Ӧ�����ָ��Ľ��  �����ǵ����-1���������Ϊ0�Ľ����ջ
        {
            inDegree[tempNode->data]--;
            if(inDegree[tempNode->data]==0)
               stack[++top]=tempNode->data;
            tempNode=tempNode->next;
        }
    }
    if(count+1 == numCourses) *returnSize=numCourses;
    else *returnSize=0;   //�����ڻ�����������������пγ̣��ͷ��ؿ�����
    /*freeǰ��������ڴ�ռ�*/
    /*free(stack);
    free(inDegree);
    for(int i=0;i<numCourses;i++)
    {
        struct MyNode* tempNode,*deleteNode;
        tempNode=G->graph[i].next;
        while(tempNode!=NULL)
        {
            deleteNode=tempNode;
            tempNode=tempNode->next;
            free(deleteNode);
        }
    }
    free(G);
    return output;
}*/


int main()
{
    int a[1][2] = { 1,0 };
    int* ab = NULL;
    int t = 2;
    int* bc = &t;
    findOrder(2, a, 1, bc, ab);
	return 0;
}