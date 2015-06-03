#include<unordered_map>
template <typename T>
struct TreeNode
{
	T val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(T x) : val(x), left(nullptr), right(nullptr){}
};


class TrieNode//根节点必须为空
{
private:
	char content;
	bool isEndOfWord;//表示当前是否是一个字符串的结尾
	std::unordered_map<char, TrieNode*> nexts;//保存所有子节点的指针

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

	bool containsSubNode(char c)//该函数判断一个字符是否在该节点的子节点中
	{
		return nexts.end() != nexts.find(c);
	}

	TrieNode* search(char c)//在所有子节点中查找是否包含元素c
	{
		std::unordered_map<char, TrieNode*>::iterator iter = nexts.find(c);
		if (iter == nexts.end())
			return nullptr;
		else
			return iter->second;
	}

	bool isWord()//判断当前的节点是否是一个字符串
	{
		return isEndOfWord;
	}
};