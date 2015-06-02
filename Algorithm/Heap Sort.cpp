#include<algorithm>
#include<iostream>
//�ѣ����ѣ����ڵ�Ҫ���ӽڵ����С�ѣ����ڵ�Ҫ���ӽڵ�С
//һ�����飬�����±�i��������ʼ�±�Ϊ0������£����ĸ��ڵ���±���(i - 1)/2, ���ӽڵ���±���2*i + 1�����ӽڵ���±���2*i + 2����Ȼ�±겻�ܳ����ѵĴ�С
//���ֶѵ����ʣ���������A���±�i��Ҫ��֤i֮���Ԫ���ǶѵĽṹ���������i���ӽڵ㶼�Ƕѣ�


void Max_Heapify(int A [], int i, int n)
{
	int left_child = 2 * i + 1;//�ֱ���������ӽڵ�
	int right_child = 2 * i + 2;
	int largest = 0;//����i�ڵ���ӽڵ���ֵ�����±�
	if (left_child < n && A[left_child] > A[i])//�Ƚ�i�ڵ�����ӽڵ�Ĵ�С
		largest = left_child;
	else
		largest = i;

	if (right_child < n && A[right_child] > A[largest])//�Ƚ�largest�����ӽڵ�Ĵ�С
		largest = right_child;

	if (largest != i)
	{
		std::swap(A[i], A[largest]);//����ֵ��Ȼ������ݹ�
		Max_Heapify(A, largest, n);
	}
}

//���ѣ��Ե����ϲ��ϵ���Max_Heapify����������һ���ѣ�����A�д�n/2 +1��n��Ԫ����ʵ��������Ҷ�ӽڵ㣬���Կ�����һ��Ԫ�صĶѣ��Ե����϶�ʣ�µĽڵ����
//Max_Heapify�Ϳ��Եõ�һ����

void Build_Max_Heap(int A [], int n)
{
	for (int i = (n - 1) / 2; i >= 0; --i)
	{
		Max_Heapify(A, i, n);
	}
}

//����������Build_Max_Heap����һ�����ѣ�Ȼ�����ν����ڵ���ѵ����һ��Ԫ�ؽ�����Ȼ�����Max_HeapifyʹA[0-n-1]���ֶѵ�����

void HeapSort(int A [], int n)
{
	Build_Max_Heap(A, n);
	for (int i = n - 1; i > 0; --i)//�����һ��Ԫ�ؿ�ʼ���������һ��Ԫ�ؽ�����Ȼ�󱣳ֶѵ����ʣ�����iֻ��Ҫ���ڶ���Ԫ�ؾͿ�����
	{
		std::swap(A[0], A[i]);
		Max_Heapify(A, 0, i);
	}
}

