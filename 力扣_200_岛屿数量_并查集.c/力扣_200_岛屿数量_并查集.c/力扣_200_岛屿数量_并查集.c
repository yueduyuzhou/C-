#include <stdio.h>

/************************************************************************************************************************************/
//����x������
int Find(int x, int* root)
{
    if (root[x] == x) { return x; }
    else { root[x] = Find(root[x], root); }
    return root[x];
}

//ͬ���±�Ϊx,y������
void Union(int x, int y, int* root, int* count)
{
    root[x] = Find(x, root);
    root[y] = Find(y, root);

    if (root[x] != root[y])
    {
        root[root[x]] = root[y];
        (*count)--;
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int row = gridSize;
    int col = *gridColSize;
    //int waters = 0;

    int root[row * col];
    int count = row * col;
    int i, j;
    //��ʼ������,���� = Ԫ��ֵ
    for (i = 0; i < row * col; i++) { root[i] = i; }

    //����grid
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (grid[i][j] == '0') { count--; }
            else
            {
                /*int flag = 1;
                while (flag != 0)
                {
                    flag = 0;
                }*/
                if (i + 1 < row && grid[i + 1][j] == '1') { Union((i + 1) * col + j, i * col + j, root, &count); }
                if (i - 1 >= 0 && grid[i - 1][j] == '1') { Union((i - 1) * col + j, i * col + j, root, &count); }
                if (j + 1 < col && grid[i][j + 1] == '1') { Union(i * col + (j + 1), i * col + j, root, &count); }
                if (j - 1 >= 0 && grid[i][j - 1] == '1') { Union(i * col + (j - 1), i * col + j, root, &count); }
            }
        }
    }
    return count;
}

int main()
{
	return 0;
}