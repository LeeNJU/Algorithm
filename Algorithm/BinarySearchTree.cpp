#include"Tree.h"
#include<stack>
template <typename T>
class BinarySearchTree
{
private:
	TreeNode<T>* root;
protected:
	void visit(const TreeNode<T>* p)//访问某一个节点
	{

	}

	TreeNode<T>* search(TreeNode<T>* p, const TreeNode<T>* node)//二叉查找树的查找操作
	{
		while (p != nullptr)
		{
			if (p->val == node->val)//找到
				return p->val;
			else if (p->val < node->val)//在右子树
				p = p->right;
			else//在左子树
				p = p->left;
		}
		return nullptr;//没有找到该元素
	}

	void preorder(const TreeNode<T>* p)//递归版前序遍历
	{
		if (p != nullptr)
		{
			visit(p);
			preorder(p->left);
			preorder(p->right);
		}
	}

	void inorder(const TreeNode<T>* p)//递归版中序遍历
	{
		if (p != nullptr)
		{
			inorder(p->left);
			visit(p);
			inorder(p->right);
		}
	}

	void postorder(const TreeNode<T>* p)//递归版后序遍历
	{
		if (p != nullptr)
		{
			postorder(p->left);
			postorder(p->right);
			visit(p);
		}
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

	TreeNode<T>* search(const TreeNode<T>* node) const//查找操作
	{
		return search(root, node);
	}

	void insert(const TreeNode<T>* node)//插入操作，用两个指针遍历整课树，p指向根节点，prev指向p节点的父节点，刚开始时prev为nullptr,两个指针逐层下降遍历二叉树
	{                        //多用prev指针，是为了当p为nullptr，找到插入位置的时候，这时prev指向父节点，方便插入
		TreeNode<T>* p = root, *prev = nullptr;
		while (p != nullptr)//prev和p逐层下降查找插入位置，p为nullptr时找到插入位置，需要通过prev的值与val的值比大小来判断插入的位置是左子树还是右子树
		{
			prev = p;
			if (p->val > node->val)
				p = p->left;
			else
				p = p->right;
		}

		if (prev == nullptr)//空树直接插入
			root = node
		else if (prev->val < node->val)//判断该插入左子节点还是右子节点
		prev->right = node;
		else
			prev->left = node;
	}

	void deleteNode(TreeNode<T>* node)//删除操作，分三种情况，1.node是页节点，没有子节点，直接删除。2.node只有左子节点或只有右子节点，把相应的左子节点或
	{                             //右子节点连接到父节点，然后删除node节点。3.node有左子节点和右子节点，找到node左子树中的最大元素（或右子树的最小元素）
		//与node交换，然后删除找到的最大元素或最小元素
		TreeNode<T>* temp = node;
		if (node != nullptr)//删除的节点必须不为空
		{
			if (node->right == nullptr)//没有右子节点，不管左子节点是否为空，把
			{

			}
		}
	}


	//二叉查找树的遍历
	void preorder()//前序遍历
	{
		preorder(root);
	}

	void inorder()//中序遍历
	{
		inorder(root);
	}

	void postorder()//后序遍历
	{
		postorder(root);
	}

	void levelorder()//层次遍历
	{

	}

	void iterativePreorder()//非递归版前序遍历
	{                       //用一个栈保存节点，先访问根节点，再把右子节点压入栈中，再把左子节点压入栈中，直到栈为空
		std::stack<TreeNode<T>*> s;
		if (root != nullptr)
		{
			s.push(root);
			while (!s.empty())
			{
				TreeNode<T>* p = s.pop();
				visit(p);
				if (p->right)//右子节点不为空，压入栈中，注意这里先把右子节点压入栈中，先入栈，后访问
					s.push(p->right);
				if (p->left)//左子节点不为空，压入栈中
					s.push(p->left);
			}
		}
	}


	void iterativeInorder()//非递归版中序遍历
	{
		std::stack<TreeNode<T>*> s;
		TreeNode<T>* p = root;
		while (!s.empty() || p != nullptr) {
			if (p != nullptr) {//把从根节点开始一直到最左边的节点上的所有节点压入栈中
				s.push(p);
				p = p->left;
			}
			else {//当p为nullptr时，弹出栈顶元素，然后把右子树的左子节点全部压入栈中
				p = s.top();
				s.pop();
				visit(p);
				p = p->right;
			}
		}
	}


	void iterativePostorder()//非递归版后序遍历
	{

	}

	void iterativeLevelorder()//非递归版层次遍历
	{

	}
};