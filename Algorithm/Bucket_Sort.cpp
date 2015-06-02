#include<vector>
#include<algorithm>
//桶排序：把输入数组A划分成n个桶，然后把数组中的元素映射到每一个桶中，然后对每个桶中的元素进行排序，最后把每个桶中的元素从小到大输出即可。其中假设数组中
//元素都是大于0的整数,桶排序最关键的就是映射，把每个元素映射到相应的桶中，这个过程已经做了简单的排序工作了，需要根据具体情况来选择桶的数量和映射函数
//映射函数要满足这个条件：如果A[i] <= A[j]，那么index(A[i]) <= index(A[j])

void Bucket_Sort(int A [], int n)
{
	std::vector<std::vector<int>> B(n,std::vector<int>());//B作为桶
	for (int i = 0; i < n; ++i)//对A中的元素取模，映射到桶号，加入到相应的桶中
		B[A[i] % n].push_back(A[i]);
	for (int i = 0; i < n; ++i)
	{
		if (!B[i].empty())//对每一个桶中的元素进行排序
		{
			std::sort(B[i].begin(), B[i].end());
		}
	}

	int index = 0;//依次把B桶中每个元素复制到数组A中
	for (int i = 0; i < n; ++i)
	{
		if (!B[i].empty())
		{
			for (int j = 0; j < B[i].size(); ++j)
				A[index++] = B[i][j];
		}
	}
}