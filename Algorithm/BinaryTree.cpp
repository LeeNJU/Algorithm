#include"Tree.h"
#include<stack>
#include<queue>
template <typename T>
class BinaryTree
{
private:
	TreeNode<T>* root;
public:
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

	void levelorder(const TreeNode<T>* p)//层次遍历
	{                                    //用一个队列保存节点，先把根节点压入队列中，再依次加入左右子节点，直到队列为空
		if (p == nullptr)
			return;

		std::queue<TreeNode<T>*> q;
		q.push(p);
		while (!q.empty())
		{
			visit(p);
			q.pop();//弹出该元素
			if (p->left)//加入左子节点
				q.push(p->left);
			if (p->right)//加入右子节点
				q.push(p->right);
		}
	}

	//二叉树的遍历
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
		levelorder(root);
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
		while (!s.empty() || p != nullptr)
		{
			if (p != nullptr) //把从根节点开始一直到最左边的节点上的所有节点压入栈中
			{
				s.push(p);
				p = p->left;
			}
			else //当p为nullptr时，弹出栈顶元素，然后把右子树的左子节点全部压入栈中
			{
				p = s.top();
				s.pop();
				visit(p);
				p = p->right;
			}
		}
	}


	void iterativePostorder()//非递归版后序遍历
	{
		TreeNode<T>*p, *q;/* p，正在访问的结点，q，刚刚访问过的结点*/
		stack<TreeNode<T>*> s;
		p = root;
		do {
			while (p != nullptr) /* 往左下走*/
			{
				s.push(p);
				p = p->left;
			}
			q = nullptr;
			while (!s.empty())
			{
				p = s.top();
				s.pop();
				if (p->right == q) /* 右孩子不存在或已被访问，访问之*/
				{
					visit(p);
					q = p; /* 保存刚访问过的结点*/
				}
				else
				{
					s.push(p);/* 当前结点不能访问，需第二次进栈*/
					p = p->right;/* 先处理右子树*/
					break;
				}
			}
		} while (!s.empty());
	}
};