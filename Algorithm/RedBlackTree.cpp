#include"Tree.h"
//RBTree是一种特殊的二叉查找树，红黑树的操作在最坏情形下为log(n),它有如下几个特点
//1.每一个节点有一个color属性，表明当前节点是红的还是黑的  2.根节点必须是黑的。 3.如果一个节点是红的，那么它的子节点必须是黑的。
//4.从一个节点到null指针的每一条路径都必须包含相同数目的黑色节点

template <typename T>
class RedBlackTree
{
private:
	RedBlackNode<T>* root;

	void left_rotate(RedBlackNode* x)//从右往左单旋
	{
		RedBlackNode* y = x->right;
		x->right = y->left;
		if (y->left != nullptr)//设置父节点
			y->left->parent = x;

		if (x == root) //x为根节点
			root = y;
		else if (x == x->parent->left)//x为其父节点的左子节点
			x->parent->left = y;
		else                    //x为其父节点的右子节点
			x->parent->right = y;

		y->left = x;
		x->parent = y;
	}

	RedBlackNode* right_rotate(RedBlackNode* t)//右单旋
	{
		RedBlackNode* y = t->right;
		t->right = y->left
	}
};