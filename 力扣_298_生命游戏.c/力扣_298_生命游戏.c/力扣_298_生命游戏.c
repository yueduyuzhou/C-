int RecordLife(int** board, int boardSize, int* boardColSize, int i, int j)
{
    int neighobrs[3] = { 0, 1, -1 };
    int sum = 0;

    for (int i2 = 0; i2 < 3; i2++)
    {
        for (int j2 = 0; j2 < 3; j2++)
        {
            if (!(neighobrs[i2] == 0 && neighobrs[j2] == 0))
            {
                int r = i + neighobrs[i2];
                int c = j + neighobrs[j2];

                if ((r < boardSize && r >= 0) && (c < *boardColSize && c >= 0) && board[r][c] == 1)
                {
                    sum += 1;
                }
            }
        }
    }

    return sum;
}

void gameOfLife(int** board, int boardSize, int* boardColSize) {
    int tmpr = boardSize;
    int tmpc = *boardColSize;
    int** tag = (int**)malloc(sizeof(int*) * tmpr);
    for (int i = 0; i < tmpr; i++)
    {
        tag[i] = (int*)malloc(sizeof(int) * tmpc);
    }

    for (int i = 0; i < tmpr; i++)
    {
        for (int j = 0; j < tmpc; j++)
        {
            tag[i][j] = board[i][j];
        }
    }

    for (int i = 0; i < tmpr; i++)
    {
        for (int j = 0; j < tmpc; j++)
        {
            int lifenum = RecordLife(tag, boardSize, boardColSize, i, j);

            if (board[i][j] == 1)
            {
                if (lifenum < 2 || lifenum > 3) { board[i][j] = 0; }
                else if (lifenum == 2 || lifenum == 3) {}
            }
            else if (board[i][j] == 0)
            {
                if (lifenum == 3) { board[i][j] = 1; }
            }
        }
    }

    //int a = RecordLife(board, boardSize, boardColSize, 2, 1);
    //printf ("%d",a);

}