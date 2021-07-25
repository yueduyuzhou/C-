struct MyNode {
    int data;
    struct MyNode* next;
};
struct HashTbl {
    int TableSize;
    struct MyNode** TheLists;
};
int NextPrime(int n)
{
    if (n % 2 == 0) n++;
    for (;; n += 2)
    {
        for (int i = 3; i <= sqrt(n); i++)
            if (n % i == 0) goto out;
        return n;
    out:;
    }
}
int Hash(int key, int TableSize)
{
    int ret = abs(key) % TableSize;
    return ret;
}
struct HashTbl* InitializeHashTbl(int TableSize)
{
    struct HashTbl* H = (struct HashTbl*)malloc(sizeof(struct HashTbl));
    H->TableSize = NextPrime(TableSize);
    H->TheLists = malloc(sizeof(struct MyNode*) * H->TableSize);
    for (int i = 0; i < H->TableSize; i++)
    {
        H->TheLists[i] = malloc(sizeof(struct MyNode));
        H->TheLists[i]->next = NULL;
        H->TheLists[i]->data = -1;
    }
    return H;
}
struct MyNode* Find(int key, struct HashTbl* H)
{
    struct MyNode* p, * l;
    l = H->TheLists[Hash(key, H->TableSize)];
    p = l->next;
    while (p != NULL && p->data != key)
        p = p->next;
    return p;
}
void Insert(int key, struct HashTbl* H)
{
    struct MyNode* Pos, * l;
    Pos = Find(key, H);
    if (Pos == NULL)
    {
        struct MyNode* NewCell = (struct MyNode*)malloc(sizeof(struct MyNode));
        l = H->TheLists[Hash(key, H->TableSize)];
        NewCell->next = l->next;
        l->next = NewCell;
        NewCell->data = key;
    }
}
void FreeHashTbl(struct HashTbl* H)
{
    struct MyNode* temp, * deleteNode;
    for (int i = 0; i < H->TableSize; i++)
    {
        temp = H->TheLists[i];
        while (temp != NULL)
        {
            deleteNode = temp;
            temp = temp->next;
            free(deleteNode);
        }
    }
    free(H);
}
int longestConsecutive(int* nums, int numsSize) {
    int max = 0;
    struct HashTbl* HashForNums = InitializeHashTbl(numsSize);
    for (int i = 0; i < numsSize; i++)            //第一次遍历数组————把数组的值放到哈希表中(同时去重)
    {
        struct MyNode* findNode = Find(nums[i], HashForNums);
        if (findNode == NULL) Insert(nums[i], HashForNums);
    }
    for (int i = 0; i < numsSize; i++)   //第二次遍历数组————找长连续序列长度
    {
        if (nums[i] == -2147483647 || Find(nums[i] - 1, HashForNums) == NULL)   //只有x-1不存在的时候再往后找(注意：前一项比较条件是确保类型为int的nums[i]在减一后不越界)
        {
            int curMax = 0, temp = 0;
            while (Find(nums[i] + temp, HashForNums) != NULL)
            {
                curMax++;
                temp++;
            }
            max = fmax(curMax, max);
        }
    }
    return max;
}
