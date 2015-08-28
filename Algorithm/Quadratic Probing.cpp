//����̽�鷨��hash��ʵ��
//insert:ͨ��hash function�����±�index��������±��λ��Ϊ�գ������Ԫ�أ������λ�ò�Ϊ�գ�����̽��index + 1�� index + 4
//index + 9, ...  ��λ�ã�ֱ��������λ��
//find:����index + 1�� index + 4�� index + 9�ķ�ʽ�������ң�ֱ���ҵ�ƥ�������������
//delete:Ҳֻ���ó�ɾ�������������
#include<vector>

template <typename T>
class HashTable
{
private:
	std::vector<T> array;
	int currentSize;

	bool isActive(int currentPos) const
	{
		return array[currentPos].info == ACTIVE;
	}

	int findPos(const T & x) const
	{
		int offset = 1;
		int currentPos = myhash(x);

		// Assuming table is half-empty, and table length is prime,
		// this loop terminates
		while (array[currentPos].info != EMPTY &&
			array[currentPos].element != x)
		{
			currentPos += offset;  // Compute ith probe
			offset += 2;
			if (currentPos >= array.size())
				currentPos -= array.size();
		}

		return currentPos;
	}

	void rehash()
	{
		vector<HashEntry> oldArray = array;

		// Create new double-sized, empty table
		array.resize(nextPrime(2 * oldArray.size()));
		for (int j = 0; j < array.size(); j++)
			array[j].info = EMPTY;

		// Copy table over
		currentSize = 0;
		for (int i = 0; i < oldArray.size(); i++)
		if (oldArray[i].info == ACTIVE)
			insert(oldArray[i].element);
	}
	int myhash(const T & x) const
	{
		int hashVal = hash(x);

		hashVal %= array.size();
		if (hashVal < 0)
			hashVal += array.size();

		return hashVal;
	}
public:
	explicit HashTable(int size = 101) : array(nextPrime(size))
	{
		makeEmpty();
	}

	bool contains(const T & x) const
	{
		return isActive(findPos(x));
	}

	void makeEmpty()
	{
		currentSize = 0;
		for (int i = 0; i < array.size(); i++)
			array[i].info = EMPTY;
	}

	bool insert(const T & x)
	{
		// Insert x as active
		int currentPos = findPos(x);
		if (isActive(currentPos))
			return false;

		array[currentPos] = HashEntry(x, ACTIVE);

		// Rehash; see Section 5.5
		if (++currentSize > array.size() / 2)
			rehash();

		return true;
	}

	bool remove(const T & x)
	{
		int currentPos = findPos(x);
		if (!isActive(currentPos))
			return false;

		array[currentPos].info = DELETED;
		return true;
	}

	enum EntryType { ACTIVE, EMPTY, DELETED };


};