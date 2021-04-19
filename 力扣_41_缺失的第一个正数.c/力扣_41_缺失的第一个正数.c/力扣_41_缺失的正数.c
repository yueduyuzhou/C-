/*int firstMissingPositive(int* nums, int numsSize){
    if (numsSize == 0) {return 1;}

    int num = 1;
    for (int i = 0; i < numsSize; i++)
    {
        int flag = 0;
        for (int j = 0; j < numsSize; j++)
        {
            if (nums[j] == num)
            {
                flag = 1;
                num++;
                break;
            }
        }
        if (flag == 0) {return num;}
    }

    return num;
}*/

int firstMissingPositive(int* nums, int numsSize) {
    if (numsSize == 0) { return 1; }

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] <= 0) { nums[i] = numsSize + 1; }
    }

    for (int i = 0; i < numsSize; i++)
    {
        if (abs(nums[i]) >= 1 && abs(nums[i]) <= numsSize)
        {
            if (nums[abs(nums[i]) - 1] > 0) { nums[abs(nums[i]) - 1] *= -1; }
        }
    }

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] > 0)
        {
            return i + 1;
        }
    }
    return numsSize + 1;
}