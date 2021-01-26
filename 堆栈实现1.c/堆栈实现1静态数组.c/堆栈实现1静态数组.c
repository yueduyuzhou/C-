#include <stdio.h>
#include <assert.h>
#include "stack.h"

#define STACK_SIZE 100    //堆栈最大长度

static STACK_TYPE stack[STACK_SIZE];
static int top_element = -1;

//压栈
void push(STACK_TYPE value)
{
	assert(!is_full());
	top_element += 1;
	stack[top_element] = value;
}

//弹出栈顶
void pop()
{
	assert(!is_empty());
	top_element -= 1;
}

//返回栈顶
STACK_TYPE top()
{
	assert(!is_empty());
	return stack[top_element];
}

//判断是否为空
int is_empty()
{
	return top_element == -1;
}

//判断是否已满
int is_full()
{
	return top_element == STACK_SIZE - 1;
}

//打印堆栈
void printStack()
{
	int i = top_element;

	if (i == -1)
	{
		printf("这是个空堆栈\n\n");
	}

	while (i != -1)
	{
		printf("%d\t", stack[i]);
	    i--;
	}
}

int main()
{
	printStack();
	push(9); push(8); push(7);
	printf("压入数据后；>\n\n");
	printStack();

	pop();
	printf("\n\n弹出栈顶后；>\n\n");
	printStack();

	printf("\n\n出栈顶；>\n\n");
	printf("%d\n", top());

	return 0;
}




