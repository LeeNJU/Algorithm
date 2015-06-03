#include"Tree.h"
template <typename T>
class BinarySearchTree
{
private:
	TreeNode<T>* root;
protected:
	T* search(TreeNode<T>* p, const T& val)//二叉查找树的查找操作
	{
		while (p != nullptr)
		{
			if (p->val == val)//找到
				return p->val;
			else if (p->val < val)//在右子树
				p = p->right;
			else//在左子树
				p = p->left;
		}
		return nullptr;//没有找到该元素
	}
public:
	BinarySearchTree()
	{
		root = nullptr;
	}
	bool isEmpty()
	{
		return root == nullptr;
	}
	T* search(const T& val) const
	{
		return search(root, val);
	}
	void insert(const T& val)//插入操作，用两个指针遍历整课树，p指向根节点，prev指向p节点的父节点，刚开始时prev为nullptr,两个指针逐层下降遍历二叉树
	{                        //多用prev指针，是为了当p为nullptr，找到插入位置的时候，这时prev指向父节点，方便插入
		TreeNode<T>* p = root, *prev = nullptr;
		while (p != nullptr)//prev和p逐层下降查找插入位置，p为nullptr时找到插入位置，需要通过prev的值与val的值比大小来判断插入的位置是左子树还是右子树
		{
			prev = p;
			if (p->val > val)
				p = p->left;
			else
				p = p->right;
		}

		if (prev == nullptr)//空数直接插入
			root = new TreeNode<T>(val);
		else if (prev->val < val)//判断该插入左子节点还是右子节点
			prev->right = new TreeNode<T>(val);
		else
			prev->left = new TreeNode<T>(val);
	}
};