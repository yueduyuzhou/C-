#include <stdio.h>

/******************************************************************************************************************************************/
//����һ��DFS
void DFS(char** grid, int rowMax, int colMax, int row, int col)
{
    //�ڵ�Ϊ'0'������
    if (grid[row][col] == '0') { return; }
    //������Ϊ'0'
    grid[row][col] = '0';

    int offset[] = { -1, 0, 1, 0, -1 };

    //����offset����
    for (int tmp = 0; tmp < 4; tmp++)
    {
        //���    ������Ч��Χ��������
        if (row + offset[tmp] < 0 || row + offset[tmp] >= rowMax || col + offset[tmp + 1] < 0 || col + offset[tmp + 1] >= colMax)
        {
            continue;
        }
        //����ݹ�
        DFS(grid, rowMax, colMax, row + offset[tmp], col + offset[tmp + 1]);
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int rowMax = gridSize;
    int colMax = gridColSize[0];
    int row = 0, col = 0;
    int retCount = 0;

    //gridΪ��ʱֱ�ӷ���
    if (gridSize == 0 || gridColSize == NULL)
    {
        return 0;
    }

    //������ά����
    for (row = 0; row < rowMax; row++)
    {
        for (col = 0; col < colMax; col++)
        {
            //���ڵ�Ϊ'0'�����������������
            if (grid[row][col] == '0')
                continue;
            //����Ϊ'0'����������1������DFS����
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