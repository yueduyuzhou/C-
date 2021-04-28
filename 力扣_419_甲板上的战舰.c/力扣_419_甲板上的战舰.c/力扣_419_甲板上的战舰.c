#include <stdio.h>

int countBattleships(char** board, int boardSize, int* boardColSize) {
    int count = 0;

    //���������װ�
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < *boardColSize; j++)
        {
            //����ս��ֻ�ܺ�������ţ�����ÿһ��ս��������϶�Ӧ��Ϊ'.'(��һ�к͵�һ�г���)
            if (board[i][j] == 'X' && (i == 0 || board[i - 1][j] == '.') && (j == 0 || board[i][j - 1] == '.'))
            {
                count++;
            }
        }
    }

    return count;
}

int main()
{
	return 0;
}