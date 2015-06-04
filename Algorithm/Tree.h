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
struct RedBlackNode
{
	T val;
	RedBlackNode* left;
	RedBlackNode* right;
	int color; //�����ڵ������ԣ�0����죬1����ڣ�Ĭ��Ϊ��
	RedBlackNode(const T& v) :val(v), left(nullptr), right(nullptr), color(1){}
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