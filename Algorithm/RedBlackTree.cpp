#include"Tree.h"
//RBTree��һ������Ķ����������������Ĳ������������Ϊlog(n),�������¼����ص�
//1.ÿһ���ڵ���һ��color���ԣ�������ǰ�ڵ��Ǻ�Ļ��Ǻڵ�  2.���ڵ�����Ǻڵġ� 3.���һ���ڵ��Ǻ�ģ���ô�����ӽڵ�����Ǻڵġ�
//4.��һ���ڵ㵽nullָ���ÿһ��·�������������ͬ��Ŀ�ĺ�ɫ�ڵ�

template <typename T>
class RedBlackTree
{
private:
	RedBlackNode<T>* root;

	RedBlackNode* left_rotate(RedBlackNode* t)//����
	{
		
	}

	RedBlackNode* right_rotate(RedBlackNode* t)//�ҵ���
	{
		RedBlackNode* y = t->right;
		t->right = y->left
	}
};