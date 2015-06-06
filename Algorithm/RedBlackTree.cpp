#include"Tree.h"
//RBTree��һ������Ķ����������������Ĳ������������Ϊlog(n),�������¼����ص�
//1.ÿһ���ڵ���һ��color���ԣ�������ǰ�ڵ��Ǻ�Ļ��Ǻڵ�  2.���ڵ�����Ǻڵġ� 3.���һ���ڵ��Ǻ�ģ���ô�����ӽڵ�����Ǻڵġ�
//4.��һ���ڵ㵽nullָ���ÿһ��·�������������ͬ��Ŀ�ĺ�ɫ�ڵ�

template <typename T>
class RedBlackTree
{
private:
	RedBlackNode<T>* root;

	void left_rotate(RedBlackNode* x)//����������
	{
		RedBlackNode* y = x->right;
		x->right = y->left;
		if (y->left != nullptr)//���ø��ڵ�
			y->left->parent = x;

		if (x == root) //xΪ���ڵ�
			root = y;
		else if (x == x->parent->left)//xΪ�丸�ڵ�����ӽڵ�
			x->parent->left = y;
		else                    //xΪ�丸�ڵ�����ӽڵ�
			x->parent->right = y;

		y->left = x;
		x->parent = y;
	}

	RedBlackNode* right_rotate(RedBlackNode* t)//�ҵ���
	{
		RedBlackNode* y = t->right;
		t->right = y->left
	}
};