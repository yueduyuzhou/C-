#include <stdio.h>

//int MaxSubseqSum1(int A[], int N)    //算法1：“暴力算”
//{
//	int ThisSum, MaxSum = 0;
//	int i, j, k;
//
//	for (i = 0; i < N; i++)   //i是子列左端位置
//	{
//		for (j = i; j < N; j++)   //j是子列右端位置
//		{
//			ThisSum = 0;   //ThisSum是A[i]加到A[j]的和
//			for (k = i; k <= j; k++)  //从i加到j
//			{
//				ThisSum += A[k];
//				if (ThisSum > MaxSum)
//				{
//					MaxSum = ThisSum;
//				}
//			}
//		}
//	}
//	return MaxSum;
//}   //三个for循环，算法复杂为O(N^3)


//int MaxSubseqSum2(int A[], int N)
//{
//	int ThisSum, MaxSum = 0;
//	int i, j;
//
//	for (i = 0; i < N; i++)   //i是子列左端位置
//	{
//		ThisSum = 0;   //ThisSum是A[i]加到A[j]的和
//		for (j = i; j < N; j++)   //j是子列右端位置
//		{
//			ThisSum += A[j];   //对于相同的i不同的j，只要在上一次（j-1项）产生的ThisSum累加A[j]即可
//			if (ThisSum > MaxSum)
//			{
//				MaxSum = ThisSum;
//			}
//		}
//	}
//	return MaxSum;
//}   //两个for循环：算法复杂度为O(N^2)


int MaxSubseqSum4(int A[], int N)   //算法4：在线算法 （算法3：分而治之略）
{
	int ThisSum, MaxSum;
	int i;
	ThisSum = MaxSum = 0;

	for (i = 0; i < N; i++)
	{
		ThisSum += A[i];   //向右累加
		if (ThisSum > MaxSum)
		{
			ThisSum = MaxSum;   
		}
		else if (ThisSum < 0)   
		{ 
			ThisSum = 0;   //当子列为负，弃之
		}
	}
	return 0;
}   //算法复杂度为：O(N)  //“在线”的意思指，每输入一个数据就进行即时处理。在任何一个地方中止输入，算法都能正确给出解


int main()   //主函数部分未完善
{
	//int A[10], N = 10;
	//scanf_s("%c", A);
	//printf("%d", MaxSubseqSum1(A, N));
	//printf("%d", MaxSubseqSum2(A, N));
	//printf("%d", MaxSubseqSum4(A, N));
	return 0;
}