/********************************************************************************************************************************/
//˼·��ȷ����ʱ�临�Ӷ�̫��

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

    //��������strs
    for (int i = 1; i < strsSize; i++)
    {
        int flag = 0;
        //�Ƚ�strs[i]��ÿһ������׵���
        for (int j = 0; j < index_size; j++)
        {
            //ֱ������һ�����
            if (isAnagram(strs[i], res[j][0]))
            {
                //�ڸ��鿪�ٱ�ԭ�ռ��һ��char**�Ĵ�С�Ŀռ䣬ͬʱ����Ĵ�С��һ
                res[j] = realloc(res[j], sizeof(char*) * (++index[j]));
                assert(res[j]);

                //���µ��ʷ������ĩβ
                res[j][index[j] - 1] = strs[i];

                //�ñ�־λ1����ʾ���ҵ���ͬ��λ����
                flag = 1;
                break;
            }
        }

        //flagΪ0��˵����û��һ����strs[i]Ϊ��ͬ��Ч��λ�ʵ���
        if (flag == 0)
        {
            //����һ���µ��飬������һ
            res = realloc(res, sizeof(char**) * (++index_size));
            assert(res);

            //���µ����п���һ������λ
            res[index_size - 1] = (char**)malloc(sizeof(char*));
            assert(res[index_size - 1]);

            //��strs[i]�����µ�����±�Ϊ0��
            res[index_size - 1][0] = strs[i];

            //��index�����м�¼���鵥����
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
    char keyStr[MAXLENGTH]; // keyֵΪ�������ַ���
    int id; // ��¼��res�е�λ��
    int count; // ��¼������Ԫ�صĸ���
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
            // HASH����û��
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
            // HASH�����м�¼
            res[tmpHash->id][tmpHash->count] = (char*)malloc(sizeof(char) * (len + 1));
            memset(res[tmpHash->id][tmpHash->count], 0, sizeof(char) * (len + 1));
            memcpy(res[tmpHash->id][tmpHash->count], strs[i], sizeof(char) * len);
            (*returnColumnSizes)[tmpHash->id] = tmpHash->count + 1;
            tmpHash->count = tmpHash->count + 1;

        }
    }

    return res;
}
