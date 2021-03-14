#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

struct Mystruct
{
    char key[20];
    int value;
    UT_hash_handle hh; //uthash���
};
//���������ĵ�����
struct Mystruct* usr = NULL;
//
void create(char key[])
{
    struct Mystruct* newHash = malloc(sizeof(struct Mystruct));
    assert(newHash);
    strcpy(newHash->key, key);
    //value��ʼ��Ϊ1
    newHash->value = 1;
    //��newHash���뵽��ϣ��
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
        if (s == NULL) {//û�ҵ�ӳ�䣬����
            create(words[i]);
        }
        else {//�ҵ�ӳ�䣬����calue+1
            s->value++;
        }
    }
    //������ĸ�����Ŵ���
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