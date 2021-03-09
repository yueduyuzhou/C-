#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdbool.h>

typedef struct chNode
{
    char ch;
    struct chNode* next;
    struct chNode* front;
}chNode;

bool isValid(char* s) {
    if (s == NULL)
        return true;

    int length = 0;
    while (*(s + length))
        length++;

    chNode* chStack = (chNode*)malloc(sizeof(chNode));
    assert(chStack);
    chStack->next = NULL;
    chStack->front = NULL;

    chNode* top = chStack;
    int i = 0;

    while (i < length) {
        chNode* newNode = (chNode*)malloc(sizeof(chNode));
        assert(newNode);
        newNode->front = NULL;
        newNode->next = NULL;
        newNode->ch = *(s + i);
        i++;
        if (chStack->next == NULL)
        {
            chStack->next = newNode;
            newNode->front = chStack;
            top = newNode;
        }
        else
        {
            char tmp;
            switch (top->ch)
            {
            case '(':
                tmp = ')';
                break;
            case '[':
                tmp = ']';
                break;
            case '{':
                tmp = '}';
                break;
            default:
                tmp = '*';
                break;
            }
            if (tmp == newNode->ch)
            {
                chNode* tmp = top;
                top = top->front;
                top->next = NULL;
                free(tmp);
            }
            else
            {
                top->next = newNode;
                newNode->front = top;
                top = newNode;
            }
        }
    }
    if (chStack->next == NULL)
        return true;
    else
        return false;
}

int main ()
{
	return 0;
}