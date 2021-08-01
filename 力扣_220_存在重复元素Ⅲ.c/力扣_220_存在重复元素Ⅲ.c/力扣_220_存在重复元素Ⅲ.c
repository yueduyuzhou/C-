
/* 解法1, 暴力查找, 超时 */
bool containsNearbyAlmostDuplicate(int* nums, int numsSize, int k, int t) {
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = 1; j <= k && j + i < numsSize; j++)
        {
            if (fabs((long)nums[i] - (long)nums[j + i]) <= t)
            {
                return true;
            }
        }
    }
    return false;
}