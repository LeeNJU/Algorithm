#include"Tree.h"
template <typename T>
class BinarySearchTree
{
private:
	TreeNode<T>* root;
protected:
	T* search(TreeNode<T>* p, const T& val)//����������Ĳ��Ҳ���
	{
		while (p != nullptr)
		{
			if (p->val == val)//�ҵ�
				return p->val;
			else if (p->val < val)//��������
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
	T* search(const T& val) const
	{
		return search(root, val);
	}
	void insert(const T& val)//���������������ָ�������������pָ����ڵ㣬prevָ��p�ڵ�ĸ��ڵ㣬�տ�ʼʱprevΪnullptr,����ָ������½�����������
	{                        //����prevָ�룬��Ϊ�˵�pΪnullptr���ҵ�����λ�õ�ʱ����ʱprevָ�򸸽ڵ㣬�������
		TreeNode<T>* p = root, *prev = nullptr;
		while (p != nullptr)//prev��p����½����Ҳ���λ�ã�pΪnullptrʱ�ҵ�����λ�ã���Ҫͨ��prev��ֵ��val��ֵ�ȴ�С���жϲ����λ��������������������
		{
			prev = p;
			if (p->val > val)
				p = p->left;
			else
				p = p->right;
		}

		if (prev == nullptr)//����ֱ�Ӳ���
			root = new TreeNode<T>(val);
		else if (prev->val < val)//�жϸò������ӽڵ㻹�����ӽڵ�
			prev->right = new TreeNode<T>(val);
		else
			prev->left = new TreeNode<T>(val);
	}
};