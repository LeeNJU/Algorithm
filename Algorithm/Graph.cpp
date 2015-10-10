//图的表示：(1)邻接矩阵(adjacent matrix),对于每一条边(u,v),用A[u][v]的值来表示是否存在，true表示存在，false表示不存在，如果一个边有权重，那么用
//A[u][v]的值设为权重，用一个很大或很小的值表示该边不存在。空间复杂度是O(n2),n为点的个数。当图很稠密，边很多的时候用这种方式比较适合，当图很稀疏，
//边很少的时候，空间浪费。
//(2)图很稀疏的时候，用邻接表(adjacency list)表示，对每一个顶点，用一个表存放这个点的所有邻接点，空间复杂度为O(|E| + |V|),该方法为图的标准表示法

//这里的图为有向图，点用0-V-1的值来表示，在实际应用中，每一个点可能不是整数，而是Vertice对象，可以用符号表来吧每一个vertice映射成数字

#include"Tree.h"

template <typename V, typename E>
class Graph
{
private:
	std::vector<V> vertices; //点的集合
	void dfs(const V& v, std::unordered_map<V, bool>& marked )
	{
		marked[v] = true; //设为true表示已经被遍历过了
		for (V vertex : v.adjacentVertex())
		{
			if (!marked[vertex])
				dfs(vertex, marked);
		}
	}
public:
	Graph(){}
	void depth_first_search(const V& v) //图的深度优先遍历，求出点v所有可达的点
	{
		std::unordered_map<V, bool> marked(vertices.size(), false); //该数组表示每个点是否被遍历过
		dfs(v, marked);
	}

	void topoSort()//拓扑排序，先找到一个入度为0的点，访问该点，然后把该点以及这点的出边全部删除
	{
		std::unordered_map<V, int> indegree;
		for (int i = 0; i < vertices.size(); ++i)//计算每个点的入度
		{
			std::list<V> li = vertices[i].adjacentVertex();
			for (int j = 0; j < li.size(); ++j)
				++indegree[li[j]];
		}


	}


	//深搜的递归实现
	/*
	procedure dfs(G, u) :
	while u has an unvisited neighbor in G
	v : = an unvisited neighbor of u
		mark v visited
		dfs(G, v)
	*/

	//深搜非递归实现，利用栈
	/*
	procedure dfs(G, s):
	S := stack containing only s
	while S not empty
	v := S.pop()
	if v not visited:
	mark v visited
	for w 2 G.neighbors(v): S.push(w)
	*/

	//广搜实现
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