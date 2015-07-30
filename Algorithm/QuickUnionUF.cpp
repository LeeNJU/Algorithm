#include<vector>
//Quick-Union������������һ�����飬ÿһ��Ԫ�ؿ���һ����������parent��ֵΪ����ڵ�ĸ��ڵ㣬��parent[i]��ֵΪi�ĸ���
//�㣬���parent[i] == i,��ʾiΪ���ڵ�
//������root�����Ĵ��ڣ���ʼ����find������union�����ĸ��Ӷȶ���O(n)
class QuickUnionUF
{
private:
	 std::vector<int> parent;
	 int root(int i)  //���Ԫ��i���ڵ����ĸ��ڵ�
	 {
		 while (i != parent[i]) 
			 i = parent[i];
		 return i;
	 }
public:
	QuickUnionUF(int N)
	{
		for (int i = 0; i < N; i++) //��ʼ��
			parent.push_back(i);
	}
	
	bool connected(int p, int q) //ͨ���Ƚ�p��q�ĸ��ڵ��Ƿ���ͬ���ж�p��q�Ƿ���ͬһ���Ӽ���������
	{
		return root(p) == root(q);
	}

	void unions(int p, int q) //�����p��q���Ӽ��������ĸ��ڵ㣬��p�ĸ��ڵ�ĸ��ڵ��Ϊq�ĸ��ڵ�
	{
		int i = root(p);
		int j = root(q);
		parent[i] = j;
	}
};


//�����QuickUnion������ִ��union������ʱ����ʱ����ܻ�Ѹ߶ȴ�����ϲ����߶�С���������棬������������ƽ��
//WeightedQuickUnion�иĽ�����һ��size�����¼ÿ���Ӽ���Ԫ�ظ�����unino�����ںϲ���ʱ�����ǰѸ߶�С�������ӵ��߶�
//���������
class WeightedQuickUnionUF
{
private:
	std::vector<int> parent;
	std::vector<int> size;  //size[i]��ʾ��iΪ���ڵ�����нڵ�����
	int root(int i)  //���Ԫ��i���ڵ����ĸ��ڵ�
	{
		while (i != parent[i])
			i = parent[i];
		return i;
	}
public:
	WeightedQuickUnionUF(int N)
	{
		for (int i = 0; i < N; i++) //��ʼ��
		{
			parent.push_back(i);
			size[i] = 1;
		}
	}

	bool connected(int p, int q) //ͨ���Ƚ�p��q�ĸ��ڵ��Ƿ���ͬ���ж�p��q�Ƿ���ͬһ���Ӽ���������
	{
		return root(p) == root(q);
	}

	void unions(int p, int q) //�����p��q���Ӽ��������ĸ��ڵ㣬��p�ĸ��ڵ�ĸ��ڵ��Ϊq�ĸ��ڵ�
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