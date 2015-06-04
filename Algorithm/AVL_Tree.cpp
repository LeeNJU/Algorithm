#include"Tree.h"
//AVL_Tree��һ�ֶ����������Ҳ��һ��ƽ��������������������ÿһ���ڵ���������߶Ⱥ��������߶ȵĲ�ܳ���1��������n��Ԫ�ص�AVL_Tree��˵�����ĸ߶�
//Ϊlog(n),������Ĳ��Ҳ����ĸ��Ӷ�ҲΪlog(n)

template <typename T>
class AVL_Tree
{
private:
	AVLNode* root;
	const int MAX_Diff;//�������������߶ȵĲ�ܳ�����ֵ��Ҳ����1

	int height(const AVLNode* node)//����ڵ�ĸ߶�
	{
		return node == nullptr ? -1 : node->height;
	}

	AVLNode* findMin(AVLNode* t)//�ҵ���С�ڵ�
	{
		if (t == nullptr)
			return t;

		while (t->left != null)//�ҵ�����ߵĽڵ㣬��Ϊ��С��
			t = t->left;
		return t;
	}

	AVLNode* findMax(AVLNode* t)//�ҵ����ڵ�
	{
		if (t == nullptr)
			return t;

		while (t->right != nullptr)//�ҵ����ұߵĵ㣬��Ϊ����
			t = t->right;
		return t;
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

	AVLNode* balance(AVLNode* t)//��AVL������ƽ��
	{
		if (t == nullptr)
			return t;

		if (height(t->left) - height(t->right) > MAX_Diff)//����Ԥ��ֵ������ƽ����
		{                                                 //�������߶ȳ���������
			if (height(t->left->left) >= height(t->left->right))//ͨ���ж�����������˭�ĸ߶ȴ����ж��ǵ�������˫��
				t = rotateWithLeftChild(t);
			else//��˫��
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

	AVLNode* insert(AVLNode* t, const AVLNode* node)//���ص�ǰ�ڵ�t�����������ɲ������֮��ĸ��ڵ�
	{
		if (t == nullptr)//Ϊ�գ�ֱ�Ӳ���
			return node;

		if (node->val < t->val)
			t->left = insert(t->left, node);//����������
		else if (t->val < node->val)
			t->right = insert(t->right, node);//����������
		else
			;  // Duplicate; do nothing
		return balance(t);
	}

	AVLNode* remove(AVLNode* t, const AVLNode* node)//ɾ������,���ص�ǰ�ڵ�t������������ɾ��������ĸ��ڵ�
	{
		if (t == nullptr)//û�ҵ�Ҫɾ���Ľڵ㣬ֱ�ӷ���
			return t;

		if (t->val < node->val)//�ȸýڵ����������
			t->right = remove(t->right, node);
		else if (t->val > node->val)//�ȸýڵ�С����������
			t->left = remove(t->left, node);
		else if (t->left != nullptr && t->right != nullptr)//�ҵ��˸ýڵ㲢�Ҹýڵ�ӵ�������ӽڵ�
		{
			AVLNode* p = findMin(t->right);//�ҵ�����������С�㣬��t�ڵ㽻��ֵ
			t->val = p->val;
			t->right = remove(t->right, p);//Ȼ����ȥɾ���ҵ�����С��
		}
		else//�ҵ��˸ýڵ㣬���Ǹýڵ����û���ӽڵ㣬����ֻ��һ���ӽڵ�
			t = t->left == nullptr ? t->right : t->left;
		return balance(t);
	}
public:
	AVL_Tree() :root(nullptr), MAX_Diff(1){}//���캯��

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
		root = remove(root, node);
	}
};