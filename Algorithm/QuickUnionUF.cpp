#include<vector>
//Quick-Union方法，还是用一个数组，每一个元素看成一个树，数组parent的值为这个节点的父节点，即parent[i]的值为i的父节
//点，如果parent[i] == i,表示i为根节点
//由于有root操作的存在，初始化，find操作和union操作的复杂度都是O(n)
class QuickUnionUF
{
private:
	 std::vector<int> parent;
	 int root(int i)  //求出元素i所在的树的根节点
	 {
		 while (i != parent[i]) 
			 i = parent[i];
		 return i;
	 }
public:
	QuickUnionUF(int N)
	{
		for (int i = 0; i < N; i++) //初始化
			parent.push_back(i);
	}
	
	bool connected(int p, int q) //通过比较p和q的根节点是否相同来判断p和q是否在同一个子集（树）中
	{
		return root(p) == root(q);
	}

	void unions(int p, int q) //先求出p和q的子集（树）的根节点，把p的根节点的父节点改为q的根节点
	{
		int i = root(p);
		int j = root(q);
		parent[i] = j;
	}
};


//上面的QuickUnion方法在执行union操作的时候，有时候可能会把高度大的树合并到高度小的树的下面，这样导致树不平衡
//WeightedQuickUnion有改进，用一个size数组记录每个子集的元素个数，unino操作在合并的时候，总是把高度小的树连接到高度
//大的树下面
class WeightedQuickUnionUF
{
private:
	std::vector<int> parent;
	std::vector<int> size;  //size[i]表示以i为根节点的树中节点数量
	int root(int i)  //求出元素i所在的树的根节点
	{
		while (i != parent[i])
			i = parent[i];
		return i;
	}
public:
	WeightedQuickUnionUF(int N)
	{
		for (int i = 0; i < N; i++) //初始化
		{
			parent.push_back(i);
			size[i] = 1;
		}
	}

	bool connected(int p, int q) //通过比较p和q的根节点是否相同来判断p和q是否在同一个子集（树）中
	{
		return root(p) == root(q);
	}

	void unions(int p, int q) //先求出p和q的子集（树）的根节点，把p的根节点的父节点改为q的根节点
	{
		int i = root(p);
		int j = root(q);
		if (i == j)
			return;
		if (size[i] < size[j])
		{
			parent[i] = j;
			size[j] += size[i];
		}
		else
		{
			parent[j] = i;
			size[i] += size[j];
		}
	}
};