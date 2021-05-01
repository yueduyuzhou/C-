/********************************************************************************************************************************/
//思路正确，但时间复杂度太高

bool isAnagram(char* s, char* t) {
    int s_hash[26] = { 0 };
    int t_hash[26] = { 0 };
    int i = 0;

    while (s[i] != '\0' && t[i] != '\0')
    {
        s_hash[s[i] - 'a']++;
        t_hash[t[i] - 'a']++;
        i++;
    }

    if (s[i] != '\0' || t[i] != '\0') { return false; }

    int s_sum = 0;
    int t_sum = 0;
    for (i = 0; i < 26; i++)
    {
        if (s_hash[i] != t_hash[i])
        {
            return false;
        }
    }

    return true;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {

    char*** res = (char***)malloc(sizeof(char**));
    assert(res);
    res[0] = (char**)malloc(sizeof(char*));
    assert(res[0]);
    res[0][0] = strs[0];

    int* index = (int*)calloc(strsSize, sizeof(int));
    assert(index);
    index[0] = 1;
    int index_size = 1;

    //遍历整个strs
    for (int i = 1; i < strsSize; i++)
    {
        int flag = 0;
        //比较strs[i]与每一个组的首单词
        for (int j = 0; j < index_size; j++)
        {
            //直到遇到一个相等
            if (isAnagram(strs[i], res[j][0]))
            {
                //在该组开辟比原空间大一个char**的大小的空间，同时改组的大小加一
                res[j] = realloc(res[j], sizeof(char*) * (++index[j]));
                assert(res[j]);

                //把新单词放入该组末尾
                res[j][index[j] - 1] = strs[i];

                //置标志位1，表示已找到相同异位词组
                flag = 1;
                break;
            }
        }

        //flag为0，说明还没有一组与strs[i]为相同有效异位词的组
        if (flag == 0)
        {
            //开辟一个新的组，组数加一
            res = realloc(res, sizeof(char**) * (++index_size));
            assert(res);

            //在新的组中开辟一个单词位
            res[index_size - 1] = (char**)malloc(sizeof(char*));
            assert(res[index_size - 1]);

            //吧strs[i]放入新的组的下标为0处
            res[index_size - 1][0] = strs[i];

            //在index数组中记录该组单词数
            index[index_size - 1]++;
        }
    }

    /*for (int i = 0; i < index_size; i++)
    {
        printf ("%d", index[i]);
    }
    printf (" %d", index_size);*/


    *returnSize = index_size;
    *returnColumnSizes = (int*)malloc(sizeof(int) * strsSize);
    assert(returnColumnSizes);
    for (int i = 0; i < index_size; i++)
    {
        returnColumnSizes[0][i] = index[i];
    }

    /*printf ("%d ", *returnSize);
    for (int i = 0; i < index_size; i++)
    {
        printf ("%d", returnColumnSizes[0][i]);
    }*/

    return res;
}

/********************************************************************************************************************************/

#define MAXLENGTH 10000
struct hashTable {
    char keyStr[MAXLENGTH]; // key值为排序后的字符串
    int id; // 记录在res中的位置
    int count; // 记录分组中元素的个数
    UT_hash_handle hh;
};


int com(const void* a_, const void* b_) {
    char* a = (char*)a_;
    char* b = (char*)b_;
    return *a - *b;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    if (strsSize == 0) return NULL;
    char*** res = (char***)malloc(sizeof(char**) * strsSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * strsSize);
    *returnSize = 0;
    struct hashTable* hashtable = NULL;
    for (int i = 0; i < strsSize; i++) {
        int len = strlen(strs[i]);
        char tmp[len + 1];
        memset(tmp, 0, sizeof(char) * (len + 1));
        memcpy(tmp, strs[i], sizeof(char) * len);
        // qsort tmp
        qsort(tmp, len, sizeof(char), com);
        struct hashTable* tmpHash;
        HASH_FIND_STR(hashtable, tmp, tmpHash);
        if (tmpHash == NULL) {
            // HASH表中没有
            tmpHash = (struct hashTable*)malloc(sizeof(struct hashTable));
            memset(tmpHash->keyStr, 0, sizeof(char) * MAXLENGTH);
            memcpy(tmpHash->keyStr, tmp, sizeof(char) * len);
            tmpHash->id = *returnSize;
            tmpHash->count = 1;
            HASH_ADD_STR(hashtable, keyStr, tmpHash);

            res[*returnSize] = (char**)malloc(sizeof(char*) * strsSize);
            res[*returnSize][tmpHash->count - 1] = (char*)malloc(sizeof(char) * (len + 1));

            memset(res[*returnSize][tmpHash->count - 1], 0, sizeof(char) * (len + 1));
            memcpy(res[*returnSize][tmpHash->count - 1], strs[i], sizeof(char) * len);
            (*returnColumnSizes)[*returnSize] = tmpHash->count;
            (*returnSize)++;
        }
        else {
            // HASH表中有记录
            res[tmpHash->id][tmpHash->count] = (char*)malloc(sizeof(char) * (len + 1));
            memset(res[tmpHash->id][tmpHash->count], 0, sizeof(char) * (len + 1));
            memcpy(res[tmpHash->id][tmpHash->count], strs[i], sizeof(char) * len);
            (*returnColumnSizes)[tmpHash->id] = tmpHash->count + 1;
            tmpHash->count = tmpHash->count + 1;

        }
    }

    return res;
}
