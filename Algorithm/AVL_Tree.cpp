#include"Tree.h"
//AVL_Tree是一种二叉查找树，也是一种平衡树，满足如下条件：每一个节点的左子树高度和右子树高度的差不能超过1。对于有n个元素的AVL_Tree来说，它的高度
//为log(n),因此它的查找操作的复杂度也为log(n)

template <typename T>
class AVL_Tree
{
private:
	AVLNode* root;

	int height(const AVLNode* node)//计算节点的高度
	{
		return node == nullptr ? -1 : node->height;
	}

	void rotateWithLeftChild(AVLNode*& k2)//左单旋转。导致不平衡的插入位置为左子树的左边
	{
		AVLNode* k1 = k2->left;
		k2->left = k1->right;
		k1->right = k2;//完成左单旋转
		k2->height = max(height(k2->left), height(k2->right)) + 1;//调整这两个节点的高度
		k1->height = max(height(k1->left), k2->height) + 1;
		k2 = k1;//函数的参数是指针的引用，这时k1是调整后的子树的根节点，该行代码的意思是k2指针指向调整后的子树的根节点
	}

	void rotateWithRightChild(AVLNode*& k1)//右单旋转，导致不平衡的插入位置为右子树的右边
	{
		AVLNode *k2 = k1->right;
		k1->right = k2->left;
		k2->left = k1;
		k1->height = max(height(k1->left), height(k1->right)) + 1;
		k2->height = max(height(k2->right), k1->height) + 1;
		k1 = k2;
	}

	void doubleWithLeftChild(AVLNode*& k3)//左双旋，先把k3的左子树右单旋一次，再把k3左单旋一次
	{
		rotateWithRightChild(k3->left);
		rotateWithLeftChild(k3);
	}

	void doubleWithRightChild(AVLNode*& k1)//右双旋，先把k1的右子树左单旋一次，再把k1右单旋一次
	{
		rotateWithLeftChild(k1->right);
		rotateWithRightChild(k1);
	}

	void insert(const AVLNode*& t, const AVLNode* node)//特别注意，这里是指针的引用！！会改变指针所本身的值
	{
		if (t == nullptr)//为空，直接插入
			t = node;
		else if (node->val < t->val)
		{
			insert(t->left, node);//插入左子树
			if (height(t->left) - height(t->right) == 2)//树不平衡了，需要进行调整
			{
				if (node->val < t->left->val)//判断需要进行单旋还是双旋
					rotateWithLeftChild(t);
				else
					doubleWithLeftChild(t);
			}
		}
		else if (t->val < node->val)
		{
			insert(t->right, node);//插入右子树
			if (height(t->right) - height(t->left) == 2)
			{
				if (t->right->val < node->val)//判断进行单旋还是双旋
					rotateWithRightChild(t);
				else
					doubleWithRightChild(t);
			}
		}
		else
			;  // Duplicate; do nothing
		t->height = max(height(t->left), height(t->right)) + 1;//插入元素后，更新root节点的高度
	}
public:
	AVL_Tree() :root(nullptr){}//构造函数

	bool isEmpty()//是否为空
	{
		return root == nullptr;
	}

	void insert(const AVLNode* node)//插入操作
	{
		insert(root, node);
	}

	void remove(const AVLNode* node)//删除操作
	{

	}
};