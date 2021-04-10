#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAX_NUM 26 

typedef struct Trie {
    char ch;
    struct Trie* child[MAX_NUM];
    int isword;
} Trie;

/** Initialize your data structure here. */

Trie* trieCreate() {
    Trie* root = (Trie*)malloc(sizeof(Trie));
    assert(root);
    memset(root, 0, sizeof(Trie));
    root->ch = '\0';
    root->isword = 0;
    return root;
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char* word) {
    Trie* p = obj;
    for (int i = 0; i < strlen(word); i++)
    {
        if (p->child[word[i] - 'a'] == NULL)
        {
            p->child[word[i] - 'a'] = (Trie*)malloc(sizeof(Trie));
            assert(p->child[word[i] - 'a']);
            memset(p->child[word[i] - 'a'], 0, sizeof(Trie));
            p->child[word[i] - 'a']->ch = word[i];
            p->child[word[i] - 'a']->isword = 0;
        }
        p = p->child[word[i] - 'a'];
    }
    p->isword = 1;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char* word) {
    Trie* p = obj;
    for (int i = 0; i < strlen(word); i++)
    {
        if (p->child[word[i] - 'a'] == NULL) { return false; }
        p = p->child[word[i] - 'a'];
    }
    if (p->isword == 1) { return true; }
    return false;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char* prefix) {
    Trie* p = obj;
    for (int i = 0; i < strlen(prefix); i++)
    {
        if (p->child[prefix[i] - 'a'] == NULL) { return false; }
        p = p->child[prefix[i] - 'a'];
    }
    return true;
}

void trieFree(Trie* obj) {
    free(obj);
}

int main()
{

	return 0;
}