#include<algorithm>
//��������:����A[p...r]�����ֳ�2�������飨����Ϊ�գ�A[p...q-1]��A[q+1..r],ʹ��A[p...q-1]�е�Ԫ�ض�С�ڵ���A[q]������С�ڵ���A[q+1..r]��Ԫ�أ��±�qҲ��
//��������м�������� Ȼ��ݹ���ã��������������������

//���������У�����Ҫ�Ĳ�����Partition���ò���������������������򣬲�������±�q,�ò�������ѡ��A[r]��Ϊ��Ԫ����������
int Partition(int A [], int p, int r)
{
	int x = A[r];//x��Ϊ��Ԫ ��������
	int i = p - 1;//iָ�����һ������ԪxС��Ԫ��
	for (int j = p; j < r; ++j)
	{
		if (A[j] <= x)
		{
			++i;//��ʱiָ���һ��������Ԫ��Ԫ�أ�Ȼ����A[j]����
			std::swap(A[i], A[j]);
		}
	}
	std::swap(A[i + 1], A[r]);//������Ԫ�������м䣬�������
	return i + 1;
}

//�������򣬲��ϵ���Partition
void QuickSort(int A [], int p, int r)
{
	if (p < r)
	{
		int q = Partition(A, p, r);
		QuickSort(A, p, q - 1);
		QuickSort(A, p + 1, r);
	}
}