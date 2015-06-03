#include"Tree.h"
#include<stack>
template <typename T>
class BinarySearchTree
{
private:
	TreeNode<T>* root;
protected:
	void visit(const TreeNode<T>* p)//����ĳһ���ڵ�
	{

	}

	TreeNode<T>* search(TreeNode<T>* p, const TreeNode<T>* node)//����������Ĳ��Ҳ���
	{
		while (p != nullptr)
		{
			if (p->val == node->val)//�ҵ�
				return p->val;
			else if (p->val < node->val)//��������
				p = p->right;
			else//��������
				p = p->left;
		}
		return nullptr;//û���ҵ���Ԫ��
	}

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

	void deleteNode(TreeNode<T>* node)//ɾ�������������������1.node��ҳ�ڵ㣬û���ӽڵ㣬ֱ��ɾ����2.nodeֻ�����ӽڵ��ֻ�����ӽڵ㣬����Ӧ�����ӽڵ��
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


	//����������ı���
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
		while (!s.empty() || p != nullptr) {
			if (p != nullptr) {//�ѴӸ��ڵ㿪ʼһֱ������ߵĽڵ��ϵ����нڵ�ѹ��ջ��
				s.push(p);
				p = p->left;
			}
			else {//��pΪnullptrʱ������ջ��Ԫ�أ�Ȼ��������������ӽڵ�ȫ��ѹ��ջ��
				p = s.top();
				s.pop();
				visit(p);
				p = p->right;
			}
		}
	}


	void iterativePostorder()//�ǵݹ��������
	{

	}

	void iterativeLevelorder()//�ǵݹ���α���
	{

	}
};