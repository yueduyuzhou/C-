#include <stdio.h>

//int MaxSubseqSum1(int A[], int N)    //�㷨1���������㡱
//{
//	int ThisSum, MaxSum = 0;
//	int i, j, k;
//
//	for (i = 0; i < N; i++)   //i���������λ��
//	{
//		for (j = i; j < N; j++)   //j�������Ҷ�λ��
//		{
//			ThisSum = 0;   //ThisSum��A[i]�ӵ�A[j]�ĺ�
//			for (k = i; k <= j; k++)  //��i�ӵ�j
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
//}   //����forѭ�����㷨����ΪO(N^3)


//int MaxSubseqSum2(int A[], int N)
//{
//	int ThisSum, MaxSum = 0;
//	int i, j;
//
//	for (i = 0; i < N; i++)   //i���������λ��
//	{
//		ThisSum = 0;   //ThisSum��A[i]�ӵ�A[j]�ĺ�
//		for (j = i; j < N; j++)   //j�������Ҷ�λ��
//		{
//			ThisSum += A[j];   //������ͬ��i��ͬ��j��ֻҪ����һ�Σ�j-1�������ThisSum�ۼ�A[j]����
//			if (ThisSum > MaxSum)
//			{
//				MaxSum = ThisSum;
//			}
//		}
//	}
//	return MaxSum;
//}   //����forѭ�����㷨���Ӷ�ΪO(N^2)


int MaxSubseqSum4(int A[], int N)   //�㷨4�������㷨 ���㷨3���ֶ���֮�ԣ�
{
	int ThisSum, MaxSum;
	int i;
	ThisSum = MaxSum = 0;

	for (i = 0; i < N; i++)
	{
		ThisSum += A[i];   //�����ۼ�
		if (ThisSum > MaxSum)
		{
			ThisSum = MaxSum;   
		}
		else if (ThisSum < 0)   
		{ 
			ThisSum = 0;   //������Ϊ������֮
		}
	}
	return 0;
}   //�㷨���Ӷ�Ϊ��O(N)  //�����ߡ�����˼ָ��ÿ����һ�����ݾͽ��м�ʱ�������κ�һ���ط���ֹ���룬�㷨������ȷ������


int main()   //����������δ����
{
	//int A[10], N = 10;
	//scanf_s("%c", A);
	//printf("%d", MaxSubseqSum1(A, N));
	//printf("%d", MaxSubseqSum2(A, N));
	//printf("%d", MaxSubseqSum4(A, N));
	return 0;
}