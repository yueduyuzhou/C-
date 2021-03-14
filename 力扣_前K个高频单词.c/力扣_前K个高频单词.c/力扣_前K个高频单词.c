#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

struct Mystruct
{
    char key[20];
    int value;
    UT_hash_handle hh; //uthash句柄
};
//存放已排序的单词组
struct Mystruct* usr = NULL;
//
void create(char key[])
{
    struct Mystruct* newHash = malloc(sizeof(struct Mystruct));
    assert(newHash);
    strcpy(newHash->key, key);
    //value初始化为1
    newHash->value = 1;
    //把newHash加入到哈希表
    HASH_ADD_STR(usr, key, newHash);
}
//
struct Mystruct* find(char key[])
{
    struct Mystruct* findHash = NULL;
    HASH_FIND_STR(usr, key, findHash);
    return findHash;
}

int sort1(struct Mystruct* a, struct Mystruct* b)
{
    return (b->value - a->value);
}

void sortnum()
{
    HASH_SORT(usr, sort1);
}

int sort2(struct Mystruct* a, struct Mystruct* b)
{
    return strcmp(a->key, b->key);
}

void sortlet()
{
    HASH_SORT(usr, sort2);
}

char** topKFrequent(char** words, int wordsSize, int k, int* returnSize) {
    struct Mystruct** ret = calloc(wordsSize, sizeof(char*));
    assert(ret);
    int retlen = 0;
    usr = NULL;

    for (int i = 0; i < wordsSize; i++)
    {
        struct Mystruct* s = find(words[i]);
        if (s == NULL) {//没找到映射，加入
            create(words[i]);
        }
        else {//找到映射，次数calue+1
            s->value++;
        }
    }
    //先排字母，再排次数
    sortlet();
    sortnum();

    struct Mystruct* tmp = usr;
    for (int i = 0; i < k; i++) {
        ret[retlen++] = tmp->key;
        tmp = tmp->hh.next;
    }

    *returnSize = retlen;
    return ret;
}

int main()
{

	return 0;
}