/**
 * 超出时间限制
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int* res = malloc(sizeof(int) * 2);
    int flag = 0;
    for (int i = 0; i < numbersSize; i++)
    {
        for (int j = 0; j < numbersSize; j++)
        {
            if (i != j && numbers[i] + numbers[j] == target)
            {
                res[0] = j + 1;
                res[1] = i + 1;
                *returnSize = 2;
                flag = 1;
                break;
            }
        }
        if (flag != 0) { break; }
    }
    return res;
}


/*******************************************************************************************/
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int* ret = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;

    for (int i = 0; i < numbersSize; ++i) {
        int low = i + 1, high = numbersSize - 1;
        while (low <= high) {
            int mid = (high - low) / 2 + low;
            if (numbers[mid] == target - numbers[i]) {
                ret[0] = i + 1, ret[1] = mid + 1;
                return ret;
            }
            else if (numbers[mid] > target - numbers[i]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
    }
    ret[0] = -1, ret[1] = -1;
    return ret;
}
