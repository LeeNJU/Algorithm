#include"Tree.h"
#include<string>

class Trie
{
private:
	TrieNode* root;
public:
	Trie()
	{
		root = new TrieNode();
	}

	bool search(std::string key)
	{
		TrieNode* p = root;
		for (int i = 0; i < key.size(); ++i)
		{
			if (!p->containsSubNode(key[i]))
				return false;
			else
				p = root->search(key[i]);
		}

		return p->isWord();
	}
};