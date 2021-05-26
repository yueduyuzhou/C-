#define LINE 50
char* optimalDivision(int* nums, int numsSize) {
    char* res = calloc(LINE, sizeof(char));
    if (numsSize == 1)
    {
        sprintf(res, "%d", nums[0]);
        return res;
    }

    if (numsSize == 2)
    {
        sprintf(res, "%d/%d", nums[0], nums[1]);
        return res;
    }

    sprintf(res, "%d/(%d", nums[0], nums[1]);
    for (int i = 2; i < numsSize; i++)
    {
        sprintf(&res[strlen(res)], "/%d", nums[i]);
    }
    res[strlen(res)] = ')';

    return res;

}

/*************************************************************************************************/
//for循环改为while程序效率上升

#define LINE 50
char* optimalDivision(int* nums, int numsSize) {
    char* res = (char*)calloc(LINE, sizeof(char));
    if (numsSize == 1)
    {
        sprintf(res, "%d", nums[0]);
        return res;
    }

    if (numsSize == 2)
    {
        sprintf(res, "%d/%d", nums[0], nums[1]);
        return res;
    }

    sprintf(res, "%d/(%d", nums[0], nums[1]);
    int i = 2;
    while (i < numsSize)
    {
        sprintf(&res[strlen(res)], "/%d", nums[i]);
        i++;
    }
    res[strlen(res)] = ')';

    return res;

}