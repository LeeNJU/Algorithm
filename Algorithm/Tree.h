template <typename T>
struct TreeNode
{
	T val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(T x) : val(x), left(nullptr), right(nullptr){}
};