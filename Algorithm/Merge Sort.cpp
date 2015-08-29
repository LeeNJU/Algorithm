#include<vector>
#include<algorithm>
#include<limits.h>
//归并排序：用合并排序法对子序列递归的排序，然后再合并两个已排序的子序列。子序列长度为1时，递归结束，单个元素被视为
//         是已排好序的,当两个子序列已排好序之后，最重要的操作就是合并这两个子序列

void Merge(int A [], int p, int q, int r)//p,q,r均为数组下标，子数组A[p..q]和A[q+1..r]
{
	int lengthA = q - p + 1;//计算两个子数组的长度
	int lengthB = r - q;

	std::vector<int> left(lengthA + 1, 0);//创建两个数组，用来保存两个子数组，然后把这两个子数组合并到原数组A中
	std::vector<int> right(lengthB + 1, 0);
	std::copy(A + p, A + q + 1, left.begin());//注意这里的下标
	std::copy(A + q + 1, A + r + 1, right.begin());
	left[lengthA] = INT_MAX;//哨兵节点在循环中用来作最后的比较，把最后一个元素和哨兵节点的无穷大进行比较
	right[lengthB] = INT_MAX;

	int i = 0, j = 0;//分别指向left和right两个子数组
	for (int k = p; k <= r; ++k)//合并两个子数组到数组A中
	{
		if (left[i] <= right[j])
		{
			A[k] = left[i];
			++i;
		}
		else
		{
			A[k] = right[j];
			++j;
		}
	}
}

//归并排序就是递归调用，直到每个子数组长度为1，然后开始自底向上进行合并操作
void MergeSort(int A [], int p, int r)//p和r为数组下标
{
	if (p < r)
	{
		int q = (p + r) / 2;//尽量把数组均分
		MergeSort(A, p, q);
		MergeSort(A, q + 1, r);
		Merge(A, p, q, r);
	}
}