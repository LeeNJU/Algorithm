#include<vector>
#include<iostream>
//计数排序：其基本思想是针对每一个输入元素x，求出小于x的元素个数，这样就可以直接把x放到它在最终输出数组的位置上。但是计数排序假设输入元素都是介于0到k之间
//的整数，其中k为某个整数

void Counting_Sort(int A [], int B [], int k, int n)//A为输入元素的数组，B为存放排序结果的数组，k见上，n为数组长度
{
	std::vector<int> C(k + 1, 0);//0到k，总共k+1个元素
	for (int i = 0; i < n; ++i)//C[i]的值为等于i的元素个数
		C[A[i]] = C[A[i]] + 1;
	for (int i = 1; i < k + 1; ++i)//C[i]包含小于或等于i的元素个数
		C[i] = C[i] + C[i - 1];
	for (int i = 0; i < n; ++i)//根据C中的个数，把A中的元素放到B中
	{
		B[--C[A[i]]] = A[i];
	}
}