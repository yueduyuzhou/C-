#include <stdio.h>
#include <assert.h>
#include "stack.h"
#include <malloc.h>

static STACK_TYPE* stack;
static int stack_size;
static int top_element = -1;

//������̬��ջ
void create_stack(size_t size)
{
	assert(stack_size == 0);

	stack_size = size;
	stack = (STACK_TYPE*)malloc(stack_size * sizeof(STACK_TYPE));
	if (stack == NULL)
		printf("�ռ����ʧ��\n");
}

//�ͷŶ�ջ�ռ�
void destroy_stack()
{
	assert(stack_size > 0);
	stack_size = 0;
	free(stack);
	stack = NULL;
}

//ѹջ
void push(STACK_TYPE value)
{
	assert(!is_full());
	top_element += 1;
	stack[top_element] = value;
}

//��ջ
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

//����ջ�Ƿ�Ϊ��
int is_empty()
{
	assert(stack_size > 0);
	return top_element == -1;
}

//����ջ�Ƿ�����
int is_full()
{
	assert(stack_size > 0);
	return top_element == stack_size - 1;
}

//��ӡ��ջ
void print()
{
	int i = top_element;
	if (i == -1)
		printf("���ǿն�ջ\n");
	while (i != -1)
		printf("%d\t", stack[i--]);
	printf("\n");
}


int main()
{
	create_stack(10);
	print();
	push(9); push(8); push(7);
	printf("ѹջ��>");
	print();
	pop();
	printf("\n��ջһ�κ�Ķ�ջ��>");
	print();
	printf("\n��ʱջ����>%d\n", top());

	return 0;
}





