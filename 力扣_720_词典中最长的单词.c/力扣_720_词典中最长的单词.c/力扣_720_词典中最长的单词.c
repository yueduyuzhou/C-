#include <stdio.h>

i#define MAX_NUM 26

int my_strcmp(char* a, char* b)
{
    int flag = 0;
    for (int i = 0; b != NULL; i++)
    {
        if (a[i] < b[i])
        {
            flag = 1;
            break;
        }
        else if (a[i] > b[i])
        {
            break;
        }
    }

    return flag;
}

int my_strlen(char* a)
{
    int len = 0;
    if (a == NULL) { return 0; }
    while (a[len++] != '\0');
    return len - 1;
}

struct Trie
{
    char ch;
    struct Trie* next[26];
    int isword;
};

struct Trie* CreateTrie()
{
    struct Trie* root = (struct Trie*)malloc(sizeof(struct Trie));
    assert(root);
    memset(root, 0, sizeof(struct Trie));
    root->ch = '\0';
    root->isword = 0;

    return root;
}

void InsertTrie(struct Trie* root, char* word)
{
    struct Trie* p = root;
    for (int i = 0; i < strlen(word); i++)
    {
        if (p->next[word[i] - 'a'] == NULL)
        {
            p->next[word[i] - 'a'] = (struct Trie*)malloc(sizeof(struct Trie));
            assert(p->next[word[i] - 'a']);
            memset(p->next[word[i] - 'a'], 0, sizeof(struct Trie));
            p->next[word[i] - 'a']->ch = word[i];
            p->next[word[i] - 'a']->isword = 0;
        }
        p = p->next[word[i] - 'a'];
    }
    p->isword = 1;
}

/*char* SearchMax (struct Trie* root, char** words, int wordsize)
{
    char* res = '\0';

    for (int i = 0; i < wordsize; i++)
    {
        int tmp = strcmp(words[i], res);
        if (res == '\0' || strlen(words[i]) >= strlen(res))
        {
            struct Trie* p = root;
            int flag = 0;
            for (int j = 0; words[i][j]; j++)
            {
                //下面的res[j]会越界
                if (p->next[words[i][j] - 'a']->isword != 1 || (res[j] != '\0' && (int)words[i][j] > (int)res[j]))
                {
                    //printf ("1");
                    flag = 1;
                    break;
                }
                p = p->next[words[i][j] - 'a'];
            }
            if (flag == 0) {res = words[i];}
        }
    }

    return res;
}*/

char* SearchMax(struct Trie* root, char** words, int wordsize)
{
    char* res = NULL;

    for (int i = 0; i < wordsize; i++)
    {
        struct Trie* p = root;
        //int tmp = my_strcmp(words[i], res);
        if (my_strlen(words[i]) > my_strlen(res) || (my_strlen(words[i]) == my_strlen(res) && my_strcmp(words[i], res) == 1))
        {
            int flag = 0;
            for (int j = 0; words[i][j]; j++)
            {
                p = p->next[words[i][j] - 'a'];
                if (p->isword != 1)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) { res = words[i]; }
        }
        printf("%s ", res);
    }

    return res;
}

void TrieFree(struct Trie* root)
{
    free(root);
    root = NULL;
}



char* longestWord(char** words, int wordsSize) {
    if (wordsSize == 1) { return words[0]; }

    struct Trie* root = CreateTrie();
    for (int i = 0; i < wordsSize; i++)
    {
        InsertTrie(root, words[i]);
    }

    char* res = SearchMax(root, words, wordsSize);
    free(root);

    return res;
}

int main()
{
    char a[8] = { 'e','n','g','l','i','s','h','\0' };
    char b[8] = { 'h','i','s','t','o','r','y','\0' };
    my_strcmp(b, a);

	return 0;
}