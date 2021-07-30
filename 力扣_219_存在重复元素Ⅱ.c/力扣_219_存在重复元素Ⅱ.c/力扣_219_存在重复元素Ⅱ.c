bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    if (k == 1 && numsSize == 1) { return false; }
    if (k == numsSize && nums[0] == nums[k - 1]) { return true; }

    for (int i = 0; i < numsSize; i++)
    {
        for (int j = 1; j <= k && i + j < numsSize; j++)
        {
            if (nums[i] == nums[i + j])
            {
                return true;
            }
        }
    }
    return false;
}




bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    if (numsSize == 0) {
        return false;
    }
    int stack[numsSize];
    int top = -1;
    int i = 0;
    stack[++top] = i++;
    while (i < numsSize) {
        while (top >= 0 && nums[i] < nums[stack[top]]) {
            top--;
        }
        // ��ջ��ʱ���ж��Ƿ������Ԫ�صļ���Ƿ�<=K
        if (top >= 0 && nums[stack[top]] == nums[i]) {
            if (i - stack[top] <= k) {
                return true;
            }
        }
        stack[++top] = i++;
    }
    return false;
}