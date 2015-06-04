#include"Tree.h"
//AVL_Tree是一种二叉查找树，也是一种平衡树，满足如下条件：每一个节点的左子树高度和右子树高度的差不能超过1。对于有n个元素的AVL_Tree来说，它的高度
//为log(n),因此它的查找操作的复杂度也为log(n)

template <typename T>
class AVL_Tree
{
private:
	AVLNode* root;
protected:
	void insert(const AVLNode* p, const AVLNode* node)
	{

	}
public:
	AVL_Tree() :root(nullptr){}//构造函数
	void insert(const AVLNode* node)
	{

	}
};