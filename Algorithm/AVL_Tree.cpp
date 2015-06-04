#include"Tree.h"
//AVL_Tree��һ�ֶ����������Ҳ��һ��ƽ��������������������ÿһ���ڵ���������߶Ⱥ��������߶ȵĲ�ܳ���1��������n��Ԫ�ص�AVL_Tree��˵�����ĸ߶�
//Ϊlog(n),������Ĳ��Ҳ����ĸ��Ӷ�ҲΪlog(n)

template <typename T>
class AVL_Tree
{
private:
	AVLNode* root;

	int height(const AVLNode* node)//����ڵ�ĸ߶�
	{
		return node == nullptr ? -1 : node->height;
	}

	AVLNode* rotateWithLeftChild(AVLNode* k2)//����ת�����²�ƽ��Ĳ���λ��Ϊ�����������
	{
		AVLNode* k1 = k2->left;
		k2->left = k1->right;
		k1->right = k2;//�������ת
		k2->height = max(height(k2->left), height(k2->right)) + 1;//�����������ڵ�ĸ߶�
		k1->height = max(height(k1->left), k2->height) + 1;
		return k1;//k1������֮��ĸ��ڵ�
	}

	AVLNode* rotateWithRightChild(AVLNode* k1)//�ҵ���ת�����²�ƽ��Ĳ���λ��Ϊ���������ұ�
	{
		AVLNode *k2 = k1->right;
		k1->right = k2->left;
		k2->left = k1;
		k1->height = max(height(k1->left), height(k1->right)) + 1;
		k2->height = max(height(k2->right), k1->height) + 1;
		return k2;//k2���ҵ�����ĸ��ڵ�
	}

	AVLNode* doubleWithLeftChild(AVLNode* k3)//��˫�����Ȱ�k3���������ҵ���һ�Σ��ٰ�k3����һ��
	{
		k3->left = rotateWithRightChild(k3->left);
		return rotateWithLeftChild(k3);
	}

	AVLNode* doubleWithRightChild(AVLNode* k1)//��˫�����Ȱ�k1������������һ�Σ��ٰ�k1�ҵ���һ��
	{
		k1->right = rotateWithLeftChild(k1->right);
		return rotateWithRightChild(k1);
	}

	AVLNode* insert(AVLNode* t, const AVLNode* node)//���ص�ǰ�ڵ�t��ɲ������֮��ĸ��ڵ�
	{
		if (t == nullptr)//Ϊ�գ�ֱ�Ӳ���
			t = node;
		else if (node->val < t->val)
		{
			t->left = insert(t->left, node);//����������
			if (height(t->left) - height(t->right) == 2)//����ƽ���ˣ���Ҫ���е���
			{
				if (node->val < t->left->val)//�ж���Ҫ���е�������˫��
					t = rotateWithLeftChild(t);
				else
					t = doubleWithLeftChild(t);
			}
		}
		else if (t->val < node->val)
		{
			t->right = insert(t->right, node);//����������
			if (height(t->right) - height(t->left) == 2)
			{
				if (t->right->val < node->val)//�жϽ��е�������˫��
					t = rotateWithRightChild(t);
				else
					t = doubleWithRightChild(t);
			}
		}
		else
			;  // Duplicate; do nothing
		t->height = max(height(t->left), height(t->right)) + 1;//����Ԫ�غ󣬸���root�ڵ�ĸ߶�
		return t;
	}
public:
	AVL_Tree() :root(nullptr){}//���캯��

	bool isEmpty()//�Ƿ�Ϊ��
	{
		return root == nullptr;
	}

	void insert(const AVLNode* node)//�������
	{
		root = insert(root, node);
	}

	void remove(const AVLNode* node)//ɾ������
	{

	}
};