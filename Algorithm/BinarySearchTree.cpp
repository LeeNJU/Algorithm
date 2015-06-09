#include"Tree.h"
#include<stack>
#include<queue>
template <typename T>
class BinarySearchTree
{
private:
	TreeNode<T>* root;

	void visit(const TreeNode<T>* p)//����ĳһ���ڵ�
	{

	}


	TreeNode<T>* search(TreeNode<T>* p, const TreeNode<T>* node)//����������Ĳ��Ҳ���
	{
		while (p != nullptr)
		{
			if (p->val == node->val)//�ҵ�
				return p;
			else if (p->val < node->val)//��������
				p = p->right;
			else//��������
				p = p->left;
		}
		return nullptr;//û���ҵ���Ԫ��
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


	TreeNode<T>* search(const TreeNode<T>* node) const//���Ҳ���
	{
		return search(root, node);
	}

	

	void insert(const TreeNode<T>* node)//���������������ָ�������������pָ����ڵ㣬prevָ��p�ڵ�ĸ��ڵ㣬�տ�ʼʱprevΪnullptr,����ָ������½�����������
	{                        //����prevָ�룬��Ϊ�˵�pΪnullptr���ҵ�����λ�õ�ʱ����ʱprevָ�򸸽ڵ㣬�������
		TreeNode<T>* p = root, *prev = nullptr;
		while (p != nullptr)//prev��p����½����Ҳ���λ�ã�pΪnullptrʱ�ҵ�����λ�ã���Ҫͨ��prev��ֵ��val��ֵ�ȴ�С���жϲ����λ��������������������
		{
			prev = p;
			if (p->val > node->val)
				p = p->left;
			else
				p = p->right;
		}

		if (prev == nullptr)//����ֱ�Ӳ���
			root = node
		else if (prev->val < node->val)//�жϸò������ӽڵ㻹�����ӽڵ�
		    prev->right = node;
		else
			prev->left = node;
	}

	void remove(TreeNode<T>* node)//ɾ�������������������1.node��ҳ�ڵ㣬û���ӽڵ㣬ֱ��ɾ����2.nodeֻ�����ӽڵ��ֻ�����ӽڵ㣬����Ӧ�����ӽڵ��
	{                             //���ӽڵ����ӵ����ڵ㣬Ȼ��ɾ��node�ڵ㡣3.node�����ӽڵ�����ӽڵ㣬�ҵ�node�������е����Ԫ�أ�������������СԪ�أ�
		//��node������Ȼ��ɾ���ҵ������Ԫ�ػ���СԪ��
		TreeNode<T>* temp = node;
		if (node != nullptr)//ɾ���Ľڵ���벻Ϊ��
		{
			if (node->right == nullptr)//û�����ӽڵ㣬�������ӽڵ��Ƿ�Ϊ�գ���
			{

			}
		}
	}

};