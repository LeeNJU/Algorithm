//分离链接法的hashtable实现
#include<vector>
#include<list>
#include<string>
#include<algorithm>

template <typename T>
class HashTable
{
private:
	std::vector<std::list<T>> theLists;   // The array of Lists
	int  currentSize;

	int nextPrime(int n)//返回一个比n大的质数
	{
		if (n % 2 == 0)
			n++;

		for (; !isPrime(n); n += 2)
			;

		return n;
	}

	bool isPrime(int n)
	{
		if (n == 2 || n == 3)
			return true;

		if (n == 1 || n % 2 == 0)
			return false;

		for (int i = 3; i * i <= n; i += 2)
		if (n % i == 0)
			return false;

		return true;
	}

	int hash(int key)//整数的hash函数
	{
		return key;
	}

	int hash(const std::string & key)//字符串对象的hash函数
	{
		int hashVal = 0;

		for (int i = 0; i < key.length(); i++)
			hashVal = 37 * hashVal + key[i];

		return hashVal;
	}

	void rehash()//再散列函数
	{
		std::vector<std::list<T>> oldLists = theLists;

		// Create new double-sized, empty table
		theLists.resize(nextPrime(2 * theLists.size()));//散列表的长度扩大比为原来长度的2倍小的质数
		for (int j = 0; j < theLists.size(); j++)//清楚散列表中的元素
			theLists[j].clear();

		// Copy table over
		currentSize = 0;
		for (int i = 0; i < oldLists.size(); i++)//把oldLists里面的元素重复插入到新的散列表中
		{
			std::list<T>::iterator itr = oldLists[i].begin();
			while (itr != oldLists[i].end())
				insert(*itr++);
		}
	}

	int myhash(const T & x) const
	{
		int hashVal = hash(x);

		hashVal %= theLists.size();
		if (hashVal < 0)
			hashVal += theLists.size();

		return hashVal;
	}

public:
	explicit HashTable(int size = 101) : currentSize(0)//默认散列表大小为101
	{
		theLists.resize(101);
	}

	bool contains(const T & x) const//判断是否包含某个元素x
	{
		const std::list<T> & whichList = theLists[myhash(x)];
		return find(whichList.begin(), whichList.end(), x) != whichList.end();
	}

	void makeEmpty()//清除散列表
	{
		for (int i = 0; i < theLists.size(); i++)
			theLists[i].clear();
	}

	bool insert(const T & x)//插入一个元素
	{
		std::list<T> & whichList = theLists[myhash(x)]; //通过hash函数计算下标
		if (find(whichList.begin(), whichList.end(), x) != whichList.end())//判断是否已经包含了当前元素
			return false;
		whichList.push_back(x);

		if (++currentSize > theLists.size())//如果元素个数超过散列表的大小，再散列
			rehash();

		return true;
	}

	bool remove(const T & x)
	{
		std::list<T> & whichList = theLists[myhash(x)];
		std::list<T>::iterator itr = find(whichList.begin(), whichList.end(), x);

		if (itr == whichList.end())
			return false;

		whichList.erase(itr);
		--currentSize;
		return true;
	}
};