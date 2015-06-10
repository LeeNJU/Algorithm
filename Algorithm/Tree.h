#include<unordered_map>
template <typename T>
struct TreeNode
{
	T val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(const T& x) : val(x), left(nullptr), right(nullptr){}
};


template <typename T>
struct AVLNode
{
	T val;
	AVLNode* left;
	AVLNode* right;
	int height;
	AVLNode(const T& x) : val(x), left(nullptr), right(nullptr),height(0){}
};

template <typename T>
struct RedBlackNode//RBTree�Ľڵ����Ҫ֪�����ڵ�
{
	T val;
	RedBlackNode* parent;
	RedBlackNode* left;
	RedBlackNode* right;
	int color; //�����ڵ������ԣ�0����죬1����ڣ�Ĭ��Ϊ��
	RedBlackNode(T& v, RedBlackNode* p = nullptr, RedBlackNode* l = nullptr, RedBlackNode* r = nullptr, int c = 0) :val(v), parent(p),left(l), right(r), color(c){}
};

class TrieNode//���ڵ����Ϊ��
{
private:
	char content;
	bool isEndOfWord;//��ʾ��ǰ�Ƿ���һ���ַ����Ľ�β
	std::unordered_map<char, TrieNode*> nexts;//���������ӽڵ��ָ��

public:
	TrieNode()
	{
		isEndOfWord = false;
	}
	TrieNode(char c) 
	{
		isEndOfWord = false;
		content = c;
	}

	bool containsSubNode(char c)//�ú����ж�һ���ַ��Ƿ��ڸýڵ���ӽڵ���
	{
		return nexts.end() != nexts.find(c);
	}

	TrieNode* search(char c)//�������ӽڵ��в����Ƿ����Ԫ��c
	{
		std::unordered_map<char, TrieNode*>::iterator iter = nexts.find(c);
		if (iter == nexts.end())
			return nullptr;
		else
			return iter->second;
	}

	bool isWord()//�жϵ�ǰ�Ľڵ��Ƿ���һ���ַ���
	{
		return isEndOfWord;
	}
};

template <typename T>
class Vertex
{
private:
	T value;
	int weight;
	std::list<Vertex<T>> adjacent; //�ڽӱ���ʾ�����������ڽӵ�
public:
	Vertex(const T& val, int w = 0) : vaule(val), weight(w){}
	T get()
	{
		return value;
	}
	void set(const T v)
	{
		value = v;
	}
	bool operator == (const Vertex<T>& v) const
	{
		return this->get() == v.get();
	}
	bool operator != (const Vertex<T>& v) const
	{
		return this->get() != v.get();
	}
	bool operator < (const Vertex<T>& v) const
	{
		return this->get() < v.get();
	}
	bool operator <= (const Vertex<T>& v) const
	{
		return this->get() <= v.get();
	}
	bool operator > (const Vertex<T>& v) const
	{
		return this->get() > v.get();
	}
	bool operator >= (const Vertex<T>& v) const
	{
		return this->get() >= v.get();
	}
	std::list<Vertex<T>> adjacentVertex()
	{
		return adjacent;
	}
};

template <typename T>
class Edge
{
private:
	Vertex<T> start;
	Vertex<T> end;
public:
	Edge(const Vertex<T>& s, const Vertex<T>& e) : start(s), end(e){}
};