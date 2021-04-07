#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MaxSize 300
struct Node
{
    short x;
    short y;
};

void BFS(char** grid, int RowSize, int ColSize, int x, int y)//, short (*viste)[MaxSize])
{
    //������У���ʼ��Ϊ0
    struct Node que[MaxSize * MaxSize];
    memset(que, 0, sizeof(struct Node) * MaxSize * MaxSize);

    //�������ͷβָ��
    int right = 0;
    int left = 0;
    //���
    que[right].x = x;
    que[right++].y = y;

    //viste[que[left].x][que[left].y] = 1;
    //���Ϊ'0'
    grid[x][y] = '0';

    //�������л���Ԫ��ʱ������ѭ��
    while (left < right)
    {
        //�ֱ�⵱ǰ�ڵ�����������Ƿ�Ϊ'1'
        //ʱ��Ӳ���Ϊ'0'
        if (que[left].x + 1 < RowSize && grid[que[left].x + 1][que[left].y] == '1') //&& !viste[que[left].x + 1][que[left].y])
        {
            grid[que[left].x + 1][que[left].y] = '0';
            que[right].x = que[left].x + 1;
            que[right].y = que[left].y;
            //viste[que[right].x][que[right].y] = 1;
            right++;
        }
        if (que[left].x - 1 >= 0 && grid[que[left].x - 1][que[left].y] == '1') //&& !viste[que[left].x - 1][que[left].y])
        {
            grid[que[left].x - 1][que[left].y] = '0';
            que[right].x = que[left].x - 1;
            que[right].y = que[left].y;
            //viste[que[right].x][que[right].y] = 1;
            right++;
        }
        if (que[left].y + 1 < ColSize && grid[que[left].x][que[left].y + 1] == '1') //&& !viste[que[left].x][que[left].y])
        {
            grid[que[left].x][que[left].y + 1] = '0';
            que[right].x = que[left].x;
            que[right].y = que[left].y + 1;
            //viste[que[right].x][que[right].y] = 1;
            right++;
        }
        if (que[left].y - 1 >= 0 && grid[que[left].x][que[left].y - 1] == '1') //&& !viste[que[left].x][que[left].y - 1])
        {
            grid[que[left].x][que[left].y - 1] = '0';
            que[right].x = que[left].x;
            que[right].y = que[left].y - 1;
            //viste[que[right].x][que[right].y] = 1;
            right++;
        }
        left++;
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    //struct Node* grtmp = (struct Node*)malloc(sizeof(struct Node));
    //assert(grtmp);
    //grtmp->x = 0;
    //grtmp->y = 0;

    //char grtmp = grid[0][0];

    //short viste[MaxSize][MaxSize];
    //memset (viste, 0, sizeof(short) * MaxSize * MaxSize);

    //��¼������
    int count = 0;
    int i = 0, j = 0;
    //��������grid
    for (i = 0; i < gridSize; i++)
    {
        for (j = 0; j < *gridColSize; j++)
        {
            //grtmp = grid[i][j];
            if (grid[i][j] == '1')
            {
                count++;
                BFS(grid, gridSize, *gridColSize, i, j);//, viste);                
            }
        }
    }

    return count;
}

int main()
{
    char** grid = { { "1", "1", "1", "1", "0" }, {"1", "1", "0", "1", "0"},{"1", "1", "0", "0", "0"},{"0", "0", "0", "0", "0"} };
    int* a;
    *a = 5;
    numIslands(grid, 4, a);
    return 0;
}