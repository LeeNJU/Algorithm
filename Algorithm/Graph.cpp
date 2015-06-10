//ͼ�ı�ʾ��(1)�ڽӾ���(adjacent matrix),����ÿһ����(u,v),��A[u][v]��ֵ����ʾ�Ƿ���ڣ�true��ʾ���ڣ�false��ʾ�����ڣ����һ������Ȩ�أ���ô��
//A[u][v]��ֵ��ΪȨ�أ���һ���ܴ���С��ֵ��ʾ�ñ߲����ڡ��ռ临�Ӷ���O(n2),nΪ��ĸ�������ͼ�ܳ��ܣ��ߺܶ��ʱ�������ַ�ʽ�Ƚ��ʺϣ���ͼ��ϡ�裬
//�ߺ��ٵ�ʱ�򣬿ռ��˷ѡ�
//(2)ͼ��ϡ���ʱ�����ڽӱ�(adjacency list)��ʾ����ÿһ�����㣬��һ�����������������ڽӵ㣬�ռ临�Ӷ�ΪO(|E| + |V|),�÷���Ϊͼ�ı�׼��ʾ��

//�����ͼΪ����ͼ������0-V-1��ֵ����ʾ����ʵ��Ӧ���У�ÿһ������ܲ�������������Vertice���󣬿����÷��ű�����ÿһ��verticeӳ�������

#include"Tree.h"

template <typename V, typename E>
class Graph
{
private:
	std::vector<V> vertices; //��ļ���
	void dfs(const V& v, std::unordered_map<V, bool>& marked )
	{
		marked[v] = true;
		for (V vertex : v.adjacentVertex())
		{
			if (!marked[vertex])
				dfs(vertex, marked);
		}
	}
public:
	Graph(){}
	void depth_first_search(const V& v) //ͼ��������ȱ����������v���пɴ�ĵ�
	{
		std::unordered_map<V, bool> marked(vertices.size(), false);
		dfs(v, marked);
	}
};