#include"Tree.h"
//RBTree��һ������Ķ����������������Ĳ������������Ϊlog(n),�������¼����ص�
//1.ÿһ���ڵ���һ��color���ԣ�������ǰ�ڵ��Ǻ�Ļ��Ǻڵ�  2.���ڵ�����Ǻڵġ� 3.���һ���ڵ��Ǻ�ģ���ô�����ӽڵ�����Ǻڵġ�
//4.��һ���ڵ㵽nullָ���ÿһ��·�������������ͬ��Ŀ�ĺ�ɫ�ڵ�

template <typename T>
class RedBlackTree
{
private:
	RedBlackNode<T>* root;
	RedBlackNode<T> dummy;//�ڱ��ڵ㣬RBTree������ָ��nullptr��ָ�붼�ĳ�ָ���ڱ��ڵ㣬��ɫΪ��ɫ

	void left_rotate(RedBlackNode* x)//����������
	{
		RedBlackNode* y = x->right;
		x->right = y->left;
		if (y->left != nullptr)//���ø��ڵ�
			y->left->parent = x;
		y->parent = x->parent;

		if (x == root) //xΪ���ڵ�
			root = y;
		else if (x == x->parent->left)//xΪ�丸�ڵ�����ӽڵ�
			x->parent->left = y;
		else                    //xΪ�丸�ڵ�����ӽڵ�
			x->parent->right = y;

		y->left = x;
		x->parent = y;
	}

	RedBlackNode* right_rotate(RedBlackNode* x)//�������ҵ���
	{
		RedBlackNode* y = x->left;
		x->left = y->right;
		if (y->right != nullptr)//���ø��ڵ�
			y->right->parent = x;
		y->parent = x->parent;

		if (x == root)
			root = y;
		else if (x == x->parent->right)
			x->parent->right = y;
		else
			x->parent->left = y;

		y->right = x;
		x->parent = y;
	}

	void RB_Transplant(RedBlackNode<T>* r, RedBlackNode<T>* u, RedBlackNode<T>* v)//�÷�������uΪ���ڵ�������滻����vΪ���ڵ������
	{                           //������δ����u��vΪnull�������Ҫע��
		if (u->parent == &dummy)
			this->root = v;
		else if (u == u->parent->left)
			u->parent->left = v;
		else
			u->parent->right = v;
		v->parent = u->parent;
	}

	void rebalance_for_insert(RedBlackNode<T>* x)//ִ�в����ɾ��������RBTree���ܲ����������������Ҫ���µ���
	{
		x->color = 0; //x����ɫ�����Ǻ�ɫ
		while (x->parent->color == 0)
		{
			if (x->parent == x->parent->parent->left)//���ڵ�Ϊ�游�ڵ�����ӽڵ�
			{
				RedBlackNode<T>* y = x->parent->parent->right; //��y��Ϊx�Ĳ����ڵ�
				if (y && y->color == 0)//��������ڵ��������ɫΪ��ɫ
				{
					x->parent->color = 1;//�Ѹ��ڵ�Ͳ����ڵ���Ϊ��ɫ
					y->color = 1;
					x->parent->parent->color = 0;//���游�ڵ���Ϊ��ɫ
					x = x->parent->parent; //�������Ͻ��м��
				}
				else  //�����ڵ㲻���ڣ����߲����ڵ�Ϊ��ɫ
				{
					if (x == x->parent->right)//���xΪ���ڵ�����ӽڵ�
					{
						x = x->parent;
						left_rotate(x);//����������
					}
					x->parent->color = 1;//���ڵ���Ϊ��ɫ
					x->parent->parent->color = 0;//�游�ڵ���Ϊ��ɫ
					right_rotate(x->parent->parent); //�������ҵ���
				}
			}
			else//���ڵ�Ϊ�游�ڵ�����ӽڵ�
			{
				RedBlackNode<T>* y = x->parent->parent->left; //��y��Ϊx�Ĳ����ڵ�
				if (y && y->color == 0)//�в����ڵ㣬������ɫΪ��ɫ
				{
					x->parent->color = 1;//���ڵ���Ϊ��ɫ
					y->color = 1;//�����ڵ���Ϊ��ɫ
					x->parent->parent->color = 0;//�游�ڵ�Ϊ��ɫ
					x = x->parent->parent;
				}
				else//�޲����ڵ㣬���߲����ڵ�Ϊ��ɫ
				{
					if (x == x->parent->left)//���xΪ���ڵ�����ӽ��
					{
						x = x->parent;
						right_rotate(x);
					}
					x->parent->color = 1;
					x->parent->parent->color = 0;
					left_rotate(x);
				}
			}
		}
		root->color = 1;//���ڵ���ԶΪ��
	}

	void rebalance_for_remove(RedBlackNode<T>* r, RedBlackNode<T>* x)
	{

	}

public:
	RedBlackTree()
	{
		dummy.color = 1;
		dummy.left = nullptr;
		dummy.right = nullptr;
		dummy.parent = nullptr;
	}

	RedBlackNode* minimum(RedBlackNode* t)//�ҵ���С�ڵ�
	{
		if (t == nullptr)
			return t;

		while (t->left != null)//�ҵ�����ߵĽڵ㣬��Ϊ��С��
			t = t->left;
		return t;
	}

	void insert(const RedBlackNode<T>* z)
	{
		if (z == nullptr)
			return;

		RedBlackNode<T>* y = &dummy; //yָ�򸸽ڵ㣬xָ��ǰ�ڵ㣬����½��ҵ������λ��
		RedBlackNode<T>* x = root;
		while (x != &dummy)
		{
			y = x;
			if (x->val > z->val)
				x = x->left;
			else
				x = x->right;
		}

		z->parent = y;
		if (y == &dummy)//������ֱ�Ӳ���
			root = z;
		else if (z->val < y->val)
			y->left = z;
		else
			y->right = z;

		z->left = &dummy;
		z->right = &dummy;
		z->color = 0;//��ɫ��Ϊ��ɫ

		rebalance_for_insert(z);
	}

	void remove(RedBlackNode<T>* z)
	{
		RedBlackNode<T>* y = z;
		RedBlackNode<T>* x;
		int y_original_color = y->color;
		if (z->left == &dummy)//���ӽڵ�Ϊ�գ����������ӽڵ�Ϊ�գ�ֱ��ɾ��
		{
			RedBlackNode<T>* x = z->right;
			RB_Transplant(this->root, z, z->right);
		}
		else if (z->right == &dummy)//���ӽڵ�Ϊ�գ�ֱ��ɾ��
		{
			x = z->left;
			RB_Transplant(this->root, z, z->left);
		}
		else //�����ӽڵ����Ϊ��
		{
			RedBlackNode<T>* y = minimum(z->right);//�ҵ���������С�ڵ�
			y_original_color = y->color;
			x = y->right;
			if (y->parent == z)//����Ӧ�ÿ���xΪnull�����
				x->parent = y;
			else
			{
				RB_Transplant(this->root, y, y->right);
				y->right = z->right;
				y->right->parent = y;
			}
			RB_Transplant(this->root, z, y);
			y->left = z->left;
			y->left->parent = y;
			y->color = z->color;
		}
		if (y_original_color == 1)
			rebalance_for_remove(this->root, x);
	}
};