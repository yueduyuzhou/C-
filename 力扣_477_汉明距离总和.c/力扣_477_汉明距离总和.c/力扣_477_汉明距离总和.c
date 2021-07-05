//超出时间限制
int totalHammingDistance(int* nums, int numsSize) {
    int sum = 0;
    int i = 0;
    for (i = 0; i < numsSize - 1; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            sum += __builtin_popcount(nums[i] ^ nums[j]);
        }
    }
    return sum;
}


//同上
int hammingDistance(intxor) {
    int res_count = 0;
    while (xor)
    {
        if (xor &1 == 1)
        {
            res_count++;
        }
        xor >>= 1;
    }
    return res_count;
}

int totalHammingDistance(int* nums, int numsSize) {
    int sum = 0;
    int i = 0;
    for (i = 0; i < numsSize - 1; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            sum += hammingDistance(nums[i] ^ nums[j]);
        }
    }
    return sum;
}

//同上
int hammingDistance(intxor) {
    int res_count = 0;
    while (xor)
    {
        xor = xor &(xor -1);
        res_count++;
    }
    return res_count;
}

int totalHammingDistance(int* nums, int numsSize) {
    int sum = 0;
    int i = 0;
    for (i = 0; i < numsSize - 1; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            sum += hammingDistance(nums[i] ^ nums[j]);
        }
    }
    return sum;
}




int totalHammingDistance(int* nums, int numsSize) {
    int ans = 0;
    for (int i = 0; i < 30; ++i) {
        int c = 0;
        for (int j = 0; j < numsSize; ++j) {
            c += (nums[j] >> i) & 1;
        }
        ans += c * (numsSize - c);
    }
    return ans;
}