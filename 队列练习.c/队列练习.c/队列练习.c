#include <stdio.h>    //队列：队头弹出，队尾插入

#define Max_size 10

struct Queue
{
	int arr[Max_size];
	int front, rear;
	int size;
};

struct Queue InitQueue()
{

	struct Queue que;
	//for (int i = 0; i < Max_size; i++)
	//{
	//	que.arr[i] = 0;
	//}
	que.front = que.rear = 0;
	que.size = 0;
	return que;
}

void InQueue(struct Queue* que, int num)
{
	if (que->size == Max_size)
		return;
	que->arr[que->rear % Max_size] = num;
	que->rear = ++que->rear % Max_size;
	que->size++;
}

int DeleteQueue(struct Queue* que)
{
	if (que->size == 0)
		return 0;
	int x = que->arr[que->front % Max_size];
	que->front = ++que->front % Max_size;
	que->size--;
	return x;
}

int FindQueue(struct Queue que, int num)
{
	if (que.size == 0)
		return 0;
	int x = que.arr[num];
	return x;
}

void ChangeQueue(struct Queue* que, int n, int Tonum)
{
	if (que->size == 0)
		return;
	que->arr[n] = Tonum;
}

void PrintQueue(struct Queue que)
{
	if (que.front == que.rear && que.size == Max_size && que.front != 0)
	{
		for (int i = que.front; i < que.rear % Max_size; i = ++i % Max_size)
		{
			printf("%d\t", que.arr[i]);
		}
		printf("\n\n");
	}
	else if (que.front == 0 && que.rear == 0 && que.size == Max_size)
	{
		for (int i = 0; i < Max_size; i++)
		{
			printf("%d\t", que.arr[i]);
		}
		printf("\n\n");
	}
	else
	{
		for (int i = que.front; i != que.rear; i = ++i % Max_size)
		{
			printf("%d\t", que.arr[i]);
		}
		printf("\n\n");
	}
}

int main()
{
	struct Queue que = InitQueue();
	
	for (int i = 10; i < 20; i++)
	{
		InQueue(&que, i);
	}
	PrintQueue(que);

	int x = DeleteQueue(&que);
	printf("出队的元素是%d\n\n", x);
	PrintQueue(que);

	x = FindQueue(que, 3);
	printf("出队的元素是%d\n\n", x);

	ChangeQueue(&que, 3, 99);
	PrintQueue(que);
	return 0;
}