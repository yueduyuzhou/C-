#include <stdio.h>
#include <stdbool.h>

#define Max_size 10

struct Stack
{
	int top;
	int arr[Max_size];
};

void InitStack(struct Stack* sta)
{
	sta->top = -1;
}

bool Push(struct Stack* sta, int num)
{
	if (sta->top == Max_size - 1)
	{
		return false;
	}
	sta->arr[++sta->top] = num;
	return true;
}

bool Pop(struct Stack* sta,int* x)
{
	if (sta->top == -1)
	{
		return false;
	}
	*x = sta->arr[sta->top--];
	return true;
}

bool GetTop(struct Stack* sta, int* x)
{
	if (sta->top == -1)
	{
		return false;
	}
	*x = sta->arr[sta->top];
	return true;
}

bool ChangeInStack(struct Stack* sta, int num)
{
	if (sta->top == -1)
	{
		return false;
	}
	sta->arr[sta->top] = num;
	return true;
}

void PrintStack(struct Stack* sta)
{
	for (int i = 0; i < sta->top + 1; i++)
	{
		printf("%d\t", sta->arr[i]);
	}
	printf("\n\n");
}

int main()
{
	int x = 0;
	struct Stack sta;
	InitStack(&sta);
	for (int i = 0; i < Max_size; i++)
	{
		Push(&sta, i);
	}
	PrintStack(&sta);

	Pop(&sta,&x);
	PrintStack(&sta);
	printf("%d\n\n", x);

	GetTop(&sta, &x);
	printf("%d\n\n", x);

	ChangeInStack(&sta, 23);
	PrintStack(&sta);
	return 0;
}