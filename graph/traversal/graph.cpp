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
#include <climits>

using namespace std;
typedef pair<int,int> Pii;
class Graph
{
	int vertices_;
	vector<Pii> *adj_list_;
	
	public:
	Graph(const int vertices):vertices_(vertices) // Vertex starts from 0
	{
		adj_list_ = new vector<Pii>[vertices_];
		cout << "Graph initialized with " << vertices_ << " vertices \n";
	}

	void add_edge(const int u, const int v, const int weight);

	/* Basic DFS and BFS */
	void BFS(const int start_vertex);
	void DFS(const int start_vertex);
	void Dijkstras(int source);

	void print_edges();
};

void Graph::add_edge(const int u, const int v, const int weight)
{
	adj_list_[u].push_back(make_pair(v, weight));
	/* Comment next line for directed Graph */
	adj_list_[v].push_back(make_pair(u, weight));
}

void Graph::print_edges()
{
	cout << "List of edges in graph\n";
	for(auto j = 0; j < vertices_; j++)
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

void Graph::Dijkstras(int source)
{
	/* Vector for distance */
	vector<int> d(vertices_, INT_MAX); //int_max = infinity for now ~ 2Billion
	/* Priority Queue for storing distance, node pair */
	priority_queue< Pii, vector<Pii> , greater<Pii> > pq;

	pq.push(make_pair(0, source));
	d[source] = 0;

	while(!pq.empty())
	{
		int u = pq.top().second; //pair is <distance, vertex>
		pq.pop();

		for (auto &i: adj_list_[u])
		{
			int v = i.first; // adjacent v to u( pair is <vertex, weight>)
			int weight = i.second; //weight from closest vertex to v in adj list

			if (d[v] > d[u] + weight)
			{
				d[v] = d[u] + weight;
				pq.push(make_pair(d[v],v)); //pair is <distance, vertex>
			}
		}
	}

	cout << "\nVertex  " << "Distance from Source" << endl;
	for (int v = 0; v < vertices_; v++)
	{
		cout << v << " \t " << d[v] << endl;

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
	cout << "Input start vertex for the traversal";
	cin >> start_vertex;
	
	g.print_edges();
	g.BFS(start_vertex);
	g.DFS(start_vertex);
	g.Dijkstras(start_vertex);
}
