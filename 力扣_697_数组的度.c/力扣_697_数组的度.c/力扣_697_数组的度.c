typedef struct
{
    int num;
    int start;
    int end;
    int cnt;
    UT_hash_handle hh;
}Hash;

int Max(int a, int b)
{
    return a > b ? a : b;
}

int Min(int a, int b)
{
    return a < b ? a : b;
}

int findShortestSubArray(int* nums, int numsSize) {
    //指向哈希表的指针
    Hash* my_hash = NULL;

    int num = 0;
    int maxcnt = 1;
    int res = numsSize;
    Hash* s = NULL;
    Hash* tmp = NULL;

    for (int i = 0; i < numsSize; i++)
    {
        num = nums[i];
        //查找哈希表中是否已存在num
        HASH_FIND_INT(my_hash, &num, s);
        if (s == NULL)
        {
            s = (Hash*)malloc(sizeof(Hash));
            assert(s);

            s->num = num;
            s->start = i;
            s->end = i;
            s->cnt = 1;
            //s加入哈希表
            HASH_ADD_INT(my_hash, num, s);
        }
        else
        {
            s->cnt++;
            s->end = i;
            //更新最大值
            maxcnt = Max(maxcnt, s->cnt);
        }
    }

    HASH_ITER(hh, my_hash, s, tmp)
    {
        //printf ("%d", res);
        if (s->cnt == maxcnt) { res = Min(res, s->end - s->start + 1); }
    }

    return res;
}