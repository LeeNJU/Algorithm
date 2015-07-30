#include<vector>
//不相交集(并查集)：包含0到n个不同的元素，这些元素分别属于不同的子集，这些子集都两两不相交，并查集有两个重要操作，
//find和union，find判断两个元素是否在同一个子集中，union操作把两个子集合并

//quick-find方法，给定一个大小为N的数组，下标0到n-1表示n个元素，数组的值表示该元素的id，如果两个元素的id一样，表示
//这两个元素属于同一个子集
//该方法的初始化和union操作复杂度为O(n)，find操作复杂度为O(1)
class QuickFindUF
{
private:
	std::vector<int> vec;

public:
	QuickFindUF(int n)
	{
		for (int i = 0; i < n; ++i) //数组初始化，每个元素的id等于自身下标，表示每个元素开始时都是一个单独的子集
			vec.push_back(i);
	}


	bool connected(int p, int q) //判断元素p和q是否在同一个子集中，只需要判断p和q的id是否相同
	{
		return vec[p] == vec[q];
	}


	void unions(int p, int q) //遍历数组，把id和pid相等的元素的id改成qid
	{
		int pid = vec[p];
		int qid = vec[q];
		for (int i = 0; i < vec.size(); ++i)
		{
			if (pid == vec[i])
				vec[i] = qid;
		}
	}

};
