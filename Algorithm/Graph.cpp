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
		marked[v] = true; //��Ϊtrue��ʾ�Ѿ�����������
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
		std::unordered_map<V, bool> marked(vertices.size(), false); //�������ʾÿ�����Ƿ񱻱�����
		dfs(v, marked);
	}

	void topoSort()//�����������ҵ�һ�����Ϊ0�ĵ㣬���ʸõ㣬Ȼ��Ѹõ��Լ����ĳ���ȫ��ɾ��
	{
		std::unordered_map<V, int> indegree;
		for (int i = 0; i < vertices.size(); ++i)//����ÿ��������
		{
			std::list<V> li = vertices[i].adjacentVertex();
			for (int j = 0; j < li.size(); ++j)
				++indegree[li[j]];
		}


	}


	//���ѵĵݹ�ʵ��
	/*
	procedure dfs(G, u) :
	while u has an unvisited neighbor in G
	v : = an unvisited neighbor of u
		mark v visited
		dfs(G, v)
	*/

	//���ѷǵݹ�ʵ�֣�����ջ
	/*
	procedure dfs(G, s):
	S := stack containing only s
	while S not empty
	v := S.pop()
	if v not visited:
	mark v visited
	for w 2 G.neighbors(v): S.push(w)
	*/

	//����ʵ��
	/*
	procedure bfs(G, s):
	Q := queue containing only s
	while Q not empty
	v := Q.front(); Q.remove front()
	for w 2 G.neighbors(v):
	if w not seen:
	mark w seen
	Q.enqueue(w)
	*/
};