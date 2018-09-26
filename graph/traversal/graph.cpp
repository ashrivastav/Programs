/* Major Graph Algorithm implemeted here */
/* Already implemented - DFS, BFS */
/* TODO: Belman Ford, Dijakstras for Single Source shortest Path */
/* TODO: Krukshal and Prims Algo for Min Spanning Tree */

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

class Graph
{
	int vertices_;
	int edges_;
	vector<pair<int, int> > *adj_list_;
	
	public:
	Graph(const int vertices):vertices_(vertices + 1) // Vertex starts from 1
	{
		adj_list_ = new vector<pair<int,int> >[vertices_];
		cout << "Graph initialized with " << vertices_ << " vertices \n";
	}

	void add_edge(const int u, const int v, const int weight);

	/* Basic DFS and BFS */
	void BFS(const int start_vertex);
	void DFS(const int start_vertex);



	void print_edges();
};

void Graph::add_edge(const int u, const int v, const int weight)
{
	adj_list_[u].push_back(make_pair(v, weight));
}

void Graph::print_edges()
{
	cout << "List of edges in graph\n";
	for(auto j = 1; j < vertices_; j++)
		for (auto &i : adj_list_[j])
		{
			cout << "Edge:"<< j << "->" << i.first << "  Weight:" << i.second << '\n';
		}
}

/* BFS */
void Graph::BFS(const int start_vertex)
{
	vector<bool> visited(vertices_, false);

	queue<int> q;
	q.push(start_vertex);

	cout << "\nBFS for the graph is as follows" << endl;
	while(!q.empty())
	{
		int vertex = q.front(); q.pop();
		
		if (visited[vertex]) // If already visited skip
			continue;

		visited[vertex] = true;
		cout << vertex << " ";

		for(auto &i : adj_list_[vertex])
		{
			if(visited[i.first] ==  false)
				q.push(i.first);

		}
	}
}
/* DFS */

void Graph::DFS(const int start_vertex)
{
	vector<bool> visited(vertices_, false);

	stack<int> stk;
	stk.push(start_vertex);

	cout << "\nDFS for the graph is as follows" << endl;

	while(!stk.empty())
	{
		auto vertex = stk.top(); stk.pop();

		if (visited[vertex])  // If already visited skip
			continue;

		visited[vertex] = true;
		cout << vertex << " ";

		for(auto &i : adj_list_[vertex]) {
			if (visited[i.first] == false)
				stk.push(i.first);
		}
	}

}



int main()
{
	int vertices = 0, edges = 0, start_vertex = 0;
	cout << "Enter number of vertices :";
	cin >> vertices;

	Graph g(vertices);

	cout << "Enter number of edges in the graph :";
	cin >> edges;

	cout << "Enter the vertices in format v1 , v2 , w (v1->v2 with weight w)\n";
	for(auto i = 0; i < edges; i++)
	{
		int u, v, weight;
		cin >> u; cin >> v ; cin >> weight;
		g.add_edge(u, v, weight);
	}

	g.print_edges();

	cout << "Input start vertex for the traversal";
	cin >> start_vertex;

	g.BFS(start_vertex);
	
	g.DFS(start_vertex);
}
