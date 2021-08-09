#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool findchar(char* hash[], char c)
{
    if (hash[c - 'a'] != NULL)
    {
        return false;
    }
    return true;
}

bool findword(char* hash[], char* word)
{
    for (int i = 0; i < 26; i++)
    {
        if (hash[i] != NULL && strcmp(hash[i], word) == 0)
        {
            return false;
        }
    }
    return true;
}

int countchar(char* s, char t)
{
    int s_len = strlen(s);
    int count = 0;
    for (int i = 0; i < s_len; i++)
    {
        if (s[i] == t) { count++; }
    }
    return count;
}

bool wordPattern(char* pattern, char* s) {
    char* hash[26] = { 0 };
    int i = 0;
    int p_len = strlen(pattern);
    int s_len = strlen(s);
    int wordsize = countchar(s, ' ') + 1;
    char* cp_s = (char*)malloc(sizeof(char) * (s_len + 1));
    char* cp_s_2 = (char*)malloc(sizeof(char) * (s_len + 1));
    char* temp = NULL;

    if (s_len != wordsize) { return false; }

    strcpy(cp_s, s);
    strcpy(cp_s_2, s);

    hash[pattern[0] - 'a'] = strtok(cp_s, " ");

    for (i = 1; i < p_len; i++)
    {
        temp = strtok(NULL, " ");
        if (findchar(hash, pattern[i]) != false && findword(hash, temp) == false) { return false; }
        if (findchar(hash, pattern[i]))
        {
            hash[pattern[i] - 'a'] = temp;
        }
    }

    //printf ("%d ", (int)pattern[0] - 'a');
    temp = strtok(cp_s_2, " ");
    if (strcmp(hash[pattern[0] - 'a'], temp) != 0) { return false; }

    for (i = 1; i < p_len; i++)
    {
        //printf ("%d ", (int)pattern[i] - 'a');
        //printf ("%d ", i);
        temp = strtok(NULL, " ");
        if (strcmp(hash[pattern[i] - 'a'], temp) != 0) { return false; }
    }

    return true;
}

/**************************************************************************************************************************************************/

#define STR_MAX 100
#define ARRAY 2
#define ARRAYLENGTH 120

typedef struct tag_hash {
    char cnt;
    char key[STR_MAX];
    UT_hash_handle hh;
}hash;

hash* g_user = NULL;

void HashAdd(char* str, char cnt)
{
    hash* s = NULL;
    HASH_FIND_STR(g_user, str, s);
    if (s == NULL) {
        s = (hash*)malloc(sizeof(hash));
        s->cnt = cnt;
        strcpy(s->key, str);
        HASH_ADD_STR(g_user, key, s);  /* 必须告诉插入函数，自己定义的hash结构中健变量的名字 */
    }
    return;
}

void DeleteAll()
{
    hash* s, * tmp;
    HASH_ITER(hh, g_user, s, tmp) {
        HASH_DEL(g_user, s);
        free(s);
    }
    g_user = NULL;
    return;
}

bool wordPattern(char* pattern, char* s) {
    hash* tmp = NULL;
    char str[ARRAY] = " ";
    char* token = strtok(s, str);
    g_user = NULL;

    int used[ARRAYLENGTH] = { 0 }; //保存已经被映射过的字符
    int pos = 0; //用于记录pattern的位置
    int patterLen = strlen(pattern);

    while (token != NULL) {
        if (pos > patterLen) {
            return false;
        }
        HASH_FIND_STR(g_user, token, tmp);
        if (tmp == NULL) {
            /* hash表中没有记录，但是used已经被使用过，那么直接返回false */
            if (used[pattern[pos] - '0']) {
                return false;
            }
            HashAdd(token, pattern[pos]);
            used[pattern[pos] - '0']++;
        }
        else {
            if (tmp->cnt != pattern[pos]) {
                return false;
            }
        }
        tmp = NULL;
        pos++;
        token = strtok(NULL, str);
    }

    if (pos < patterLen) {
        return false;
    }
    DeleteAll();
    return true;
}


int main ()
{



	return 0;
}