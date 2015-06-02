#include<algorithm>
//快速排序:数组A[p...r]被划分成2个子数组（可能为空）A[p...q-1]和A[q+1..r],使得A[p...q-1]中的元素都小于等于A[q]，并且小于等于A[q+1..r]的元素，下标q也在
//这个过程中计算出来。 然后递归调用，对两个子数组进行排序

//快速排序中，最重要的操作是Partition，该操作对子数组进行重新排序，并计算出下标q,该操作总是选择A[r]作为主元来划分数组
int Partition(int A [], int p, int r)
{
	int x = A[r];//x作为主元 划分数组
	int i = p - 1;//i指向最后一个比主元x小的元素
	for (int j = p; j < r; ++j)
	{
		if (A[j] <= x)
		{
			++i;//这时i指向第一个大于主元的元素，然后与A[j]交换
			std::swap(A[i], A[j]);
		}
	}
	std::swap(A[i + 1], A[r]);//最后把主元交换到中间，完成排序
	return i + 1;
}

//快速排序，不断调用Partition
void QuickSort(int A [], int p, int r)
{
	if (p < r)
	{
		int q = Partition(A, p, r);
		QuickSort(A, p, q - 1);
		QuickSort(A, p + 1, r);
	}
}