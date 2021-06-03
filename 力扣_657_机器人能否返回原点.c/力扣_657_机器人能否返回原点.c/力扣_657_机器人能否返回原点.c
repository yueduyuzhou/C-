bool judgeCircle(char* moves) {
    int x = 0;
    int y = 0;

    int i = 0;
    while (moves[i] != '\0')
    {
        switch (moves[i])
        {
        case 'R':
            x++;
            break;
        case 'L':
            x--;
            break;
        case 'U':
            y++;
            break;
        case 'D':
            y--;
            break;
        }
        i++;
    }

    if (x == 0 && y == 0)
    {
        return true;
    }
    return false;
}

/*******************************************************************************/