int min(int a, int b)
{
    return a < b ? a : b;
}

int countBinarySubstrings(char* s) {
    int len = strlen(s);
    int* arr = (int*)calloc(len, sizeof(int));
    assert(arr);

    int i = 1;
    int index = 0;
    arr[0] = 1;
    while (s[i] != '\0')
    {
        if (s[i] == s[i - 1])
        {
            arr[index]++;
        }
        else
        {
            index++;
            arr[index]++;
        }

        i++;
    }


    int sum = 0;
    i = 0;
    for (int j = 1; j <= index; j++, i++)
    {
        sum += min(arr[i], arr[j]);
    }

    return sum;
}


