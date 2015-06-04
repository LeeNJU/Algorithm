#include"Tree.h"
#include<stack>
#include<queue>
template <typename T>
class BinaryTree
{
private:
	TreeNode<T>* root;
public:
	void preorder(const TreeNode<T>* p)//�ݹ��ǰ�����
	{
		if (p != nullptr)
		{
			visit(p);
			preorder(p->left);
			preorder(p->right);
		}
	}

	void inorder(const TreeNode<T>* p)//�ݹ���������
	{
		if (p != nullptr)
		{
			inorder(p->left);
			visit(p);
			inorder(p->right);
		}
	}

	void postorder(const TreeNode<T>* p)//�ݹ��������
	{
		if (p != nullptr)
		{
			postorder(p->left);
			postorder(p->right);
			visit(p);
		}
	}

	void levelorder(const TreeNode<T>* p)//��α���
	{                                    //��һ�����б���ڵ㣬�ȰѸ��ڵ�ѹ������У������μ��������ӽڵ㣬ֱ������Ϊ��
		if (p == nullptr)
			return;

		std::queue<TreeNode<T>*> q;
		q.push(p);
		while (!q.empty())
		{
			visit(p);
			q.pop();//������Ԫ��
			if (p->left)//�������ӽڵ�
				q.push(p->left);
			if (p->right)//�������ӽڵ�
				q.push(p->right);
		}
	}

	//�������ı���
	void preorder()//ǰ�����
	{
		preorder(root);
	}

	void inorder()//�������
	{
		inorder(root);
	}

	void postorder()//�������
	{
		postorder(root);
	}

	void levelorder()//��α���
	{
		levelorder(root);
	}

	void iterativePreorder()//�ǵݹ��ǰ�����
	{                       //��һ��ջ����ڵ㣬�ȷ��ʸ��ڵ㣬�ٰ����ӽڵ�ѹ��ջ�У��ٰ����ӽڵ�ѹ��ջ�У�ֱ��ջΪ��
		std::stack<TreeNode<T>*> s;
		if (root != nullptr)
		{
			s.push(root);
			while (!s.empty())
			{
				TreeNode<T>* p = s.pop();
				visit(p);
				if (p->right)//���ӽڵ㲻Ϊ�գ�ѹ��ջ�У�ע�������Ȱ����ӽڵ�ѹ��ջ�У�����ջ�������
					s.push(p->right);
				if (p->left)//���ӽڵ㲻Ϊ�գ�ѹ��ջ��
					s.push(p->left);
			}
		}
	}


	void iterativeInorder()//�ǵݹ���������
	{
		std::stack<TreeNode<T>*> s;
		TreeNode<T>* p = root;
		while (!s.empty() || p != nullptr)
		{
			if (p != nullptr) //�ѴӸ��ڵ㿪ʼһֱ������ߵĽڵ��ϵ����нڵ�ѹ��ջ��
			{
				s.push(p);
				p = p->left;
			}
			else //��pΪnullptrʱ������ջ��Ԫ�أ�Ȼ��������������ӽڵ�ȫ��ѹ��ջ��
			{
				p = s.top();
				s.pop();
				visit(p);
				p = p->right;
			}
		}
	}


	void iterativePostorder()//�ǵݹ��������
	{
		TreeNode<T>*p, *q;/* p�����ڷ��ʵĽ�㣬q���ոշ��ʹ��Ľ��*/
		stack<TreeNode<T>*> s;
		p = root;
		do {
			while (p != nullptr) /* ��������*/
			{
				s.push(p);
				p = p->left;
			}
			q = nullptr;
			while (!s.empty())
			{
				p = s.top();
				s.pop();
				if (p->right == q) /* �Һ��Ӳ����ڻ��ѱ����ʣ�����֮*/
				{
					visit(p);
					q = p; /* ����շ��ʹ��Ľ��*/
				}
				else
				{
					s.push(p);/* ��ǰ��㲻�ܷ��ʣ���ڶ��ν�ջ*/
					p = p->right;/* �ȴ���������*/
					break;
				}
			}
		} while (!s.empty());
	}
};