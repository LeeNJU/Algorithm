//�������ӷ���hashtableʵ��
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

	int nextPrime(int n)//����һ����n�������
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

	int hash(int key)//������hash����
	{
		return key;
	}

	int hash(const std::string & key)//�ַ��������hash����
	{
		int hashVal = 0;

		for (int i = 0; i < key.length(); i++)
			hashVal = 37 * hashVal + key[i];

		return hashVal;
	}

	void rehash()//��ɢ�к���
	{
		std::vector<std::list<T>> oldLists = theLists;

		// Create new double-sized, empty table
		theLists.resize(nextPrime(2 * theLists.size()));//ɢ�б�ĳ��������Ϊԭ�����ȵ�2��С������
		for (int j = 0; j < theLists.size(); j++)//���ɢ�б��е�Ԫ��
			theLists[j].clear();

		// Copy table over
		currentSize = 0;
		for (int i = 0; i < oldLists.size(); i++)//��oldLists�����Ԫ���ظ����뵽�µ�ɢ�б���
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
	explicit HashTable(int size = 101) : currentSize(0)//Ĭ��ɢ�б��СΪ101
	{
		theLists.resize(101);
	}

	bool contains(const T & x) const//�ж��Ƿ����ĳ��Ԫ��x
	{
		const std::list<T> & whichList = theLists[myhash(x)];
		return find(whichList.begin(), whichList.end(), x) != whichList.end();
	}

	void makeEmpty()//���ɢ�б�
	{
		for (int i = 0; i < theLists.size(); i++)
			theLists[i].clear();
	}

	bool insert(const T & x)//����һ��Ԫ��
	{
		std::list<T> & whichList = theLists[myhash(x)]; //ͨ��hash���������±�
		if (find(whichList.begin(), whichList.end(), x) != whichList.end())//�ж��Ƿ��Ѿ������˵�ǰԪ��
			return false;
		whichList.push_back(x);

		if (++currentSize > theLists.size())//���Ԫ�ظ�������ɢ�б�Ĵ�С����ɢ��
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