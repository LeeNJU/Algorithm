#include<vector>
class QuickFindUF
{
private:
	std::vector<int> vec;

public:
	QuickFindUF(int n)
	{
		for (int i = 0; i < n; ++i)
		{
			vec.push_back(i);
		}
	}
	bool connected(int p, int q);
	void unions(int p, int q);

};