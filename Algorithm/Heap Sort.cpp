#include<algorithm>
#include<iostream>
//堆：最大堆，父节点要比子节点大，最小堆，父节点要比子节点小
//一个数组，给定下标i，数组起始下标为0的情况下，它的父节点的下标是(i - 1)/2, 左子节点的下标是2*i + 1，右子节点的下标是2*i + 2，当然下标不能超过堆的大小
//保持堆的性质：给定数组A和下标i，要保证i之后的元素是堆的结构（这里假设i的子节点都是堆）


void Max_Heapify(int A [], int i, int n)
{
	int left_child = 2 * i + 1;//分别算出左右子节点
	int right_child = 2 * i + 2;
	int largest = 0;//保存i节点和子节点中值最大的下标
	if (left_child < n && A[left_child] > A[i])//比较i节点和左子节点的大小
		largest = left_child;
	else
		largest = i;

	if (right_child < n && A[right_child] > A[largest])//比较largest和右子节点的大小
		largest = right_child;

	if (largest != i)
	{
		std::swap(A[i], A[largest]);//交换值，然后继续递归
		Max_Heapify(A, largest, n);
	}
}

//建堆：自底向上不断调用Max_Heapify方法来构造一个堆，数组A中从n/2 +1到n的元素其实都是树的叶子节点，可以看成是一个元素的堆，自底向上对剩下的节点调用
//Max_Heapify就可以得到一个堆

void Build_Max_Heap(int A [], int n)
{
	for (int i = (n - 1) / 2; i >= 0; --i)
	{
		Max_Heapify(A, i, n);
	}
}

//堆排序：先用Build_Max_Heap建立一个最大堆，然后依次将根节点与堆的最后一个元素交换，然后调用Max_Heapify使A[0-n-1]保持堆的性质

void HeapSort(int A [], int n)
{
	Build_Max_Heap(A, n);
	for (int i = n - 1; i > 0; --i)//从最后一个元素开始，依次与第一个元素交换，然后保持堆的性质，其中i只需要到第二个元素就可以了
	{
		std::swap(A[0], A[i]);
		Max_Heapify(A, 0, i);
	}
}

