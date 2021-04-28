#include <stdio.h>

int countBattleships(char** board, int boardSize, int* boardColSize) {
    int count = 0;

    //遍历整个甲板
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < *boardColSize; j++)
        {
            //由于战舰只能横或竖着排，所以每一艘战舰的左和上都应该为'.'(第一行和第一列除外)
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