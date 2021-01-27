#include <stdio.h>
#include <assert.h>
#include "stack.h"
#include <malloc.h>

static STACK_TYPE* stack;
static int stack_size;
static int top_element = -1;

//´´½¨¶¯Ì¬¶ÑÕ»
void create_stack(size_t size)
{
	assert(stack_size == 0);

	stack_size = size;
	stack = (STACK_TYPE*)malloc(stack_size * sizeof(STACK_TYPE));
	if (stack == NULL)
		printf("¿Õ¼ä·ÖÅäÊ§°Ü\n");
}

//ÊÍ·Å¶ÑÕ»¿Õ¼ä
void destroy_stack()
{
	assert(stack_size > 0);
	stack_size = 0;
	free(stack);
	stack = NULL;
}

//Ñ¹Õ»
void push(STACK_TYPE value)
{
	assert(!is_full());
	top_element += 1;
	stack[top_element] = value;
}

//³öÕ»
void pop()
{
	assert(!is_empty());
	top_element -= 1;
}

//·µ»ØÕ»¶¥
STACK_TYPE top()
{
	assert(!is_empty());
	return stack[top_element];
}

//¼ì²â¶ÑÕ»ÊÇ·ñÎª¿Õ
int is_empty()
{
	assert(stack_size > 0);
	return top_element == -1;
}

//¼ì²â¶ÑÕ»ÊÇ·ñÒÑÂú
int is_full()
{
	assert(stack_size > 0);
	return top_element == stack_size - 1;
}

//´òÓ¡¶ÑÕ»
void print()
{
	int i = top_element;
	if (i == -1)
		printf("ÕâÊÇ¿Õ¶ÑÕ»\n");
	while (i != -1)
		printf("%d\t", stack[i--]);
	printf("\n");
}


int main()
{
	create_stack(10);
	print();
	push(9); push(8); push(7);
	printf("Ñ¹Õ»ºó£º>");
	print();
	pop();
	printf("\n³öÕ»Ò»´ÎºóµÄ¶ÑÕ»£º>");
	print();
	printf("\n´ËÊ±Õ»¶¥£º>%d\n", top());

	return 0;
}





