#include"Tree.h"
//AVL_Tree是一种二叉查找树，也是一种平衡树，满足如下条件：每一个节点的左子树高度和右子树高度的差不能超过1。对于有n个元素的AVL_Tree来说，它的高度
//为log(n),因此它的查找操作的复杂度也为log(n)

template <typename T>
class AVL_Tree
{
private:
	AVLNode* root;
	const int MAX_Diff;//左右两课子树高度的差不能超过的值，也就是1

	int height(const AVLNode* node)//计算节点的高度
	{
		return node == nullptr ? -1 : node->height;
	}

	AVLNode* findMin(AVLNode* t)//找到最小节点
	{
		if (t == nullptr)
			return t;

		while (t->left != null)//找到最左边的节点，即为最小点
			t = t->left;
		return t;
	}

	AVLNode* findMax(AVLNode* t)//找到最大节点
	{
		if (t == nullptr)
			return t;

		while (t->right != nullptr)//找到最右边的点，即为最大点
			t = t->right;
		return t;
	}

	AVLNode* rotateWithLeftChild(AVLNode* k2)//左单旋转。导致不平衡的插入位置为左子树的左边
	{
		AVLNode* k1 = k2->left;
		k2->left = k1->right;
		k1->right = k2;//完成左单旋转
		k2->height = max(height(k2->left), height(k2->right)) + 1;//调整这两个节点的高度
		k1->height = max(height(k1->left), k2->height) + 1;
		return k1;//k1是左单旋之后的根节点
	}

	AVLNode* rotateWithRightChild(AVLNode* k1)//右单旋转，导致不平衡的插入位置为右子树的右边
	{
		AVLNode *k2 = k1->right;
		k1->right = k2->left;
		k2->left = k1;
		k1->height = max(height(k1->left), height(k1->right)) + 1;
		k2->height = max(height(k2->right), k1->height) + 1;
		return k2;//k2是右单旋后的根节点
	}

	AVLNode* doubleWithLeftChild(AVLNode* k3)//左双旋，先把k3的左子树右单旋一次，再把k3左单旋一次
	{
		k3->left = rotateWithRightChild(k3->left);
		return rotateWithLeftChild(k3);
	}

	AVLNode* doubleWithRightChild(AVLNode* k1)//右双旋，先把k1的右子树左单旋一次，再把k1右单旋一次
	{
		k1->right = rotateWithLeftChild(k1->right);
		return rotateWithRightChild(k1);
	}

	AVLNode* balance(AVLNode* t)//对AVL树进行平衡
	{
		if (t == nullptr)
			return t;

		if (height(t->left) - height(t->right) > MAX_Diff)//超过预定值，树不平衡了
		{                                                 //左子树高度超过右子树
			if (height(t->left->left) >= height(t->left->right))//通过判断左右子树的谁的高度大，来判断是单旋还是双旋
				t = rotateWithLeftChild(t);
			else//左双旋
				t = doubleWithLeftChild(t);
		}
		else
		{
			if (height(t->right) - height(t->left) > MAX_Diff)
			{
				if (height(t->right->right) >= height(t->right->left))
					t = rotateWithRightChild(t);
				else
					t = doubleWithRightChild(t);
			}
		}
		t->height = max(height(t->left), height(t->right)) + 1;
		return t;
	}

	AVLNode* insert(AVLNode* t, const AVLNode* node)//返回当前节点t这个子树下完成插入操作之后的根节点
	{
		if (t == nullptr)//为空，直接插入
			return node;

		if (node->val < t->val)
			t->left = insert(t->left, node);//插入左子树
		else if (t->val < node->val)
			t->right = insert(t->right, node);//插入右子树
		else
			;  // Duplicate; do nothing
		return balance(t);
	}

	AVLNode* remove(AVLNode* t, const AVLNode* node)//删除操作,返回当前节点t这个子树下完成删除操作后的根节点
	{
		if (t == nullptr)//没找到要删除的节点，直接返回
			return t;

		if (t->val < node->val)//比该节点大，在右子树
			t->right = remove(t->right, node);
		else if (t->val > node->val)//比该节点小，在左子树
			t->left = remove(t->left, node);
		else if (t->left != nullptr && t->right != nullptr)//找到了该节点并且该节点拥有左右子节点
		{
			AVLNode* p = findMin(t->right);//找到右子树的最小点，和t节点交换值
			t->val = p->val;
			t->right = remove(t->right, p);//然后再去删除找到的最小点
		}
		else//找到了该节点，但是该节点可能没有子节点，可能只有一个子节点
			t = t->left == nullptr ? t->right : t->left;
		return balance(t);
	}
public:
	AVL_Tree() :root(nullptr), MAX_Diff(1){}//构造函数

	bool isEmpty()//是否为空
	{
		return root == nullptr;
	}

	void insert(const AVLNode* node)//插入操作
	{
		root = insert(root, node);
	}

	void remove(const AVLNode* node)//删除操作
	{
		root = remove(root, node);
	}
};