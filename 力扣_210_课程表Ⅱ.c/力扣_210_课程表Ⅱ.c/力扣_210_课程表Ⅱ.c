#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//邻接表节点
struct adjNode {
    int arrnum;
    struct adjNode* next;
};
//邻接表
struct Node {
    int into;
    struct adjNode* next;
    struct adjNode* tmp;
};

//创建邻接表
struct Node* CreateAdj(int size)
{
    struct Node* adj = (struct Node*)malloc(sizeof(struct Node) * size);
    assert(adj);

    //初始化
    for (int i = 0; i < size; i++)
    {
        adj[i].into = 0;
        adj[i].next = NULL;
        adj[i].tmp = NULL;
    }

    return adj;
}

//创建邻接表节点
struct adjNode* CreateAdjNode(int arrnum)
{
    struct adjNode* newNode = (struct adjNode*)malloc(sizeof(struct adjNode));
    assert(newNode);
    
    //初始化
    newNode->arrnum = arrnum;
    newNode->next = NULL;

    return newNode;
}

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    struct Node* adj = CreateAdj(numCourses);

    for (int i = 0; i < prerequisitesSize; i++)
    {
        //防止tmp和next指向不同地方
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

    //创建栈和结果数组
    int* stack = (int*)malloc(sizeof(int) * numCourses);
    //int* stack = (int*)calloc(numCourses, sizeof(int));
    assert(stack);
    int* rst = (int*)malloc(sizeof(int) * numCourses);
    //int* rst = (int*)calloc(numCourses, sizeof(int));
    assert(rst);

    int count = 0;
    int sttmp = -1;
    int retmp = -1;

    //把此时into = 0的节点入栈
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
    int count=-1; //记录pop出的结点数 用于最后比较是否有环存在(这里从-1开始 用作输出数组的下标  在最后比较的时候应+1)
    int* inDegree=(int*)malloc(sizeof(int)*numCourses);   //inDegree记录结点的入度
    memset(inDegree,0,sizeof(int)*numCourses);
    int* stack=(int*)malloc(sizeof(int)*numCourses);  //用栈来存放入度为0的结点
    int top=-1;
    /*创建邻接表*/
    /*struct Graph* G=(struct Graph*)malloc(sizeof(struct Graph));
    G->graph=(struct MyNode*)malloc(sizeof(struct MyNode)*numCourses);
    for(int i=0;i<numCourses;i++)
    {
        G->graph[i].data=0;
        G->graph[i].next=NULL;
    }
    for(int i=0;i<prerequisitesSize;i++)
    {
        struct MyNode* tempNode=(struct MyNode*)malloc(sizeof(struct MyNode)); //创建新结点，并用头插法插入邻接表中
        tempNode->data=prerequisites[i][0];
        tempNode->next=G->graph[ prerequisites[i][1] ].next;
        G->graph[ prerequisites[i][1] ].next=tempNode;
        inDegree[ prerequisites[i][0] ]++;   //被指向的那个结点入度加一
    }
    /*先遍历一次所有节点  把入度为零的结点入栈*/
    /*for(int i=0;i<numCourses;i++)
       if(inDegree[i]==0)
          stack[++top]=i;
    /*while循环进行排序*/
    /*while(top!=-1)
    {
        int tempV=stack[top--];
        output[++count]=tempV;
        struct MyNode* tempNode=G->graph[tempV].next;
        while(tempNode!=NULL)         //遍历邻接表对应结点所指向的结点  把他们的入度-1，并把入度为0的结点入栈
        {
            inDegree[tempNode->data]--;
            if(inDegree[tempNode->data]==0)
               stack[++top]=tempNode->data;
            tempNode=tempNode->next;
        }
    }
    if(count+1 == numCourses) *returnSize=numCourses;
    else *returnSize=0;   //若存在环，即不可能完成所有课程，就返回空数组
    /*free前面申请的内存空间*/
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