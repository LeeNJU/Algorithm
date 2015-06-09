#include"Tree.h"
//RBTree是一种特殊的二叉查找树，红黑树的操作在最坏情形下为log(n),它有如下几个特点
//1.每一个节点有一个color属性，表明当前节点是红的还是黑的  2.根节点必须是黑的。 3.如果一个节点是红的，那么它的子节点必须是黑的。
//4.从一个节点到null指针的每一条路径都必须包含相同数目的黑色节点

template <typename T>
class RedBlackTree
{
private:
	RedBlackNode<T>* root;
	RedBlackNode<T> dummy;//哨兵节点，RBTree中所有指向nullptr的指针都改成指向哨兵节点，颜色为黑色

	void left_rotate(RedBlackNode* x)//从右往左单旋
	{
		RedBlackNode* y = x->right;
		x->right = y->left;
		if (y->left != nullptr)//设置父节点
			y->left->parent = x;
		y->parent = x->parent;

		if (x == root) //x为根节点
			root = y;
		else if (x == x->parent->left)//x为其父节点的左子节点
			x->parent->left = y;
		else                    //x为其父节点的右子节点
			x->parent->right = y;

		y->left = x;
		x->parent = y;
	}

	RedBlackNode* right_rotate(RedBlackNode* x)//从左往右单旋
	{
		RedBlackNode* y = x->left;
		x->left = y->right;
		if (y->right != nullptr)//设置父节点
			y->right->parent = x;
		y->parent = x->parent;

		if (x == root)
			root = y;
		else if (x == x->parent->right)
			x->parent->right = y;
		else
			x->parent->left = y;

		y->right = x;
		x->parent = y;
	}

	void rebalance_for_insert(RedBlackNode<T>* x)//执行插入或删除操作后，RBTree可能不满足条件，因此需要重新调整
	{
		x->color = 0; //x的颜色必须是红色
		while (x->parent->color == 0)
		{
			if (x->parent == x->parent->parent->left)//父节点为祖父节点的左子节点
			{
				RedBlackNode<T>* y = x->parent->parent->right; //把y设为x的伯父节点
				if (y && y->color == 0)//如果伯父节点存在且颜色为红色
				{
					x->parent->color = 1;//把父节点和伯父节点设为黑色
					y->color = 1;
					x->parent->parent->color = 0;//把祖父节点设为红色
					x = x->parent->parent; //从下往上进行检查
				}
				else  //伯父节点不存在，或者伯父节点为黑色
				{
					if (x == x->parent->right)//如果x为父节点的右子节点
					{
						x = x->parent;
						left_rotate(x);//从右往左单旋
					}
					x->parent->color = 1;//父节点设为黑色
					x->parent->parent->color = 0;//祖父节点设为红色
					right_rotate(x->parent->parent); //从左往右单旋
				}
			}
			else//父节点为祖父节点的右子节点
			{
				RedBlackNode<T>* y = x->parent->parent->left; //把y设为x的伯父节点
				if (y && y->color == 0)//有伯父节点，并且颜色为红色
				{
					x->parent->color = 1;//父节点设为黑色
					y->color = 1;//伯父节点设为黑色
					x->parent->parent->color = 0;//祖父节点为红色
					x = x->parent->parent;
				}
				else//无伯父节点，或者伯父节点为黑色
				{
					if (x == x->parent->left)//如果x为父节点的左子结点
					{
						x = x->parent;
						right_rotate(x);
					}
					x->parent->color = 1;
					x->parent->parent->color = 0;
					left_rotate(x);
				}
			}
		}
		root->color = 1;//根节点永远为黑
	}

public:
	RedBlackTree()
	{
		dummy.color = 1;
		dummy.left = nullptr;
		dummy.right = nullptr;
		dummy.parent = nullptr;
	}
	void insert(const RedBlackNode<T>* z)
	{
		if (z == nullptr)
			return;

		RedBlackNode<T>* y = &dummy; //y指向父节点，x指向当前节点，逐层下降找到插入的位置
		RedBlackNode<T>* x = root;
		while (x != &dummy)
		{
			y = x;
			if (x->val > z->val)
				x = x->left;
			else
				x = x->right;
		}

		z->parent = y;
		if (y == &dummy)//空树，直接插入
			root = z;
		else if (z->val < y->val)
			y->left = z;
		else
			y->right = z;

		z->left = &dummy;
		z->right = &dummy;
		z->color = 0;//颜色设为红色

		rebalance_for_insert(z);
	}
};