#include<unordered_map>
template <typename T>
struct TreeNode
{
	T val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(T x) : val(x), left(nullptr), right(nullptr){}
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