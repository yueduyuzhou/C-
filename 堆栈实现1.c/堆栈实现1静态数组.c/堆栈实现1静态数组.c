#include <stdio.h>
#include <assert.h>
#include "stack.h"

#define STACK_SIZE 100    //��ջ��󳤶�

static STACK_TYPE stack[STACK_SIZE];
static int top_element = -1;

//ѹջ
void push(STACK_TYPE value)
{
	assert(!is_full());
	top_element += 1;
	stack[top_element] = value;
}

//����ջ��
void pop()
{
	assert(!is_empty());
	top_element -= 1;
}

//����ջ��
STACK_TYPE top()
{
	assert(!is_empty());
	return stack[top_element];
}

//�ж��Ƿ�Ϊ��
int is_empty()
{
	return top_element == -1;
}

//�ж��Ƿ�����
int is_full()
{
	return top_element == STACK_SIZE - 1;
}

//��ӡ��ջ
void printStack()
{
	int i = top_element;

	if (i == -1)
	{
		printf("���Ǹ��ն�ջ\n\n");
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
	printf("ѹ�����ݺ�>\n\n");
	printStack();

	pop();
	printf("\n\n����ջ����>\n\n");
	printStack();

	printf("\n\n��ջ����>\n\n");
	printf("%d\n", top());

	return 0;
}




