#include <stdio.h>

/******************************************************************************************************************************************/
//方法一：DFS
void DFS(char** grid, int rowMax, int colMax, int row, int col)
{
    //节点为'0'，返回
    if (grid[row][col] == '0') { return; }
    //否则置为'0'
    grid[row][col] = '0';

    int offset[] = { -1, 0, 1, 0, -1 };

    //遍历offset数组
    for (int tmp = 0; tmp < 4; tmp++)
    {
        //如果    超出有效范围，就跳过
        if (row + offset[tmp] < 0 || row + offset[tmp] >= rowMax || col + offset[tmp + 1] < 0 || col + offset[tmp + 1] >= colMax)
        {
            continue;
        }
        //否则递归
        DFS(grid, rowMax, colMax, row + offset[tmp], col + offset[tmp + 1]);
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int rowMax = gridSize;
    int colMax = gridColSize[0];
    int row = 0, col = 0;
    int retCount = 0;

    //grid为空时直接返回
    if (gridSize == 0 || gridColSize == NULL)
    {
        return 0;
    }

    //遍历二维网格
    for (row = 0; row < rowMax; row++)
    {
        for (col = 0; col < colMax; col++)
        {
            //若节点为'0'，不做处理继续遍历
            if (grid[row][col] == '0')
                continue;
            //若不为'0'，计数器加1，进入DFS函数
            retCount++;
            DFS(grid, rowMax, colMax, row, col);
        }
    }
    return retCount;
}

int main()
{
	return 0;
}