#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

struct adjNode
{
    int arrnum;
    struct adjNode* next;
};

struct Node
{
    //int val;
    int into;
    struct adjNode* next;
    struct adjNode* tmp;
};

struct Node* CreateAdj(int size)
{
    struct Node* adj = (struct Node*)malloc(sizeof(struct Node) * size);
    assert(adj);

    for (int i = 0; i < size; i++)
    {
        //adj[i]->val = 0;
        adj[i].into = 0;
        adj[i].next = NULL;
        adj[i].tmp = NULL;
    }

    return adj;
}

struct adjNode* CreateAdjNode(int arrnum)
{
    struct adjNode* newNode = (struct adjNode*)malloc(sizeof(struct adjNode));
    assert(newNode);

    newNode->arrnum = arrnum;
    newNode->next = NULL;

    return newNode;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    struct Node* adj = CreateAdj(numCourses);
    //int flag = 0;
    for (int i = 0; i < prerequisitesSize; i++)
    {
        if (adj[prerequisites[i][1]].tmp == NULL)
        {
            adj[prerequisites[i][0]].into++;
            //printf ("%d %d",prerequisites[i][0], prerequisites[i][1]);
            struct adjNode* newNode = CreateAdjNode(prerequisites[i][0]);
            //printf ("%d ",newNode->arrnum);
            adj[prerequisites[i][1]].next = newNode;
            adj[prerequisites[i][1]].tmp = adj[prerequisites[i][1]].next;
            //printf ("%d",adj[prerequisites[i][1]].next->arrnum);
            //adj[prerequisites[i][1]].tmp = adj[prerequisites[i][1]].tmp->next;
        }
        else
        {
            adj[prerequisites[i][0]].into++;
            //printf ("%d %d",prerequisites[i][0], prerequisites[i][1]);
            struct adjNode* newNode = CreateAdjNode(prerequisites[i][0]);
            //printf ("%d ",newNode->arrnum);
            adj[prerequisites[i][1]].tmp->next = newNode;
            //printf ("%d",adj[prerequisites[i][1]].next->arrnum);
            adj[prerequisites[i][1]].tmp = adj[prerequisites[i][1]].tmp->next;
        }
    }

    //¼ÆÊýÆ÷
    int count = 0;
    int* stack = (int*)malloc(sizeof(int) * numCourses);
    assert(stack);
    int sttmp = -1;
    for (int i = 0; i < numCourses; i++)
    {
        if (adj[i].into == 0) { stack[++sttmp] = i; }
    }

    while (1)
    {
        //printf ("%d ", adj[0].next->arrnum);
        if (sttmp != -1)
        {
            int k = stack[sttmp--];
            //printf ("%d",k);
            //printf ("%d", adj[k].next->arrnum);
            struct adjNode* po = adj[k].next;
            //printf ("%d", po->arrnum);
            while (po)
            {
                //printf ("1");
                adj[po->arrnum].into--;
                if (adj[po->arrnum].into == 0) { stack[++sttmp] = po->arrnum; }
                po = po->next;
            }

            count++;
            //printf ("%d ",count);
        }
        else
        {
            break;
        }
    }
    printf("%d ", count);
    return count == numCourses;
}

int main()
{
    int m[1][2] = { {1,0} };
    canFinish(2, m, 1, 2);

	return 0;
}