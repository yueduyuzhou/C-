#include <stdio.h>
#include <assert.h>
#include "stack.h"
#include <malloc.h>

#define FALSE 0

//¶¨ÒåÒ»¸ö¶ÑÕ»½á¹¹Ìå
struct STACK_NODE
{
	STACK_TYPE value;
	struct STACK_NODE* next;
}StackNode;

static StackNode* stack;

void destroy_stack()
{
	while (!is_empty())
		pop();
}

//Ñ¹Õ»
void push(STACK_TYPE value)
{
	StackNode* newNode;
	newNode = (StackNode*)malloc(sizeof(StackNode));
	assert(newNode);
	if (newNode == NULL)
		printf("¿Õ¼ä·ÖÅäÊ§°Ü£¡\n");
	newNode->value = value;
	newNode->next = stack;
	stack = newNode;
}

//³öÕ»
void pop()
{
	StackNode* firstNode;

	assert(!is_empty());
	firstNode = stack;
	stack = firstNode->next;
	free(firstNode);
}

//·µ»ØÕ»¶¥Öµ
STACK_TYPE top()
{
	assert(!is_empty());
	return stack->value;
}

//²â¿Õ
int is_empty()
{
	return stack == NULL;
}

//²âÂú
int is_full()
{
	return FALSE;
}

void print()
{
	StackNode* p_Node;
	p_Node = stack;
	printf("´òÓ¡Á´Ê½¶ÑÕ»£º>");
	if (p_Node == NULL)
		printf("¶ÑÕ»Îª¿Õ\n");
	while (p_Node != NULL)
	{
		printf("%d", p_Node->value);
		p_Node = p_Node->next;
	}
	printf("\n");
}

int main()
{
	print();

	push(9); push(8); push(7);
	print();

	pop();
	print();

	top();
	print();

	return 0;
}





