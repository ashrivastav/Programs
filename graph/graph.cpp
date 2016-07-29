#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

typedef list<pair<int,int>> lii;
class Graph
{
    int vertices;
    int size;
    int edges;
    vector<lii> adj_list;
    public:
    Graph(const auto);
    void BFS(const auto start_vertex);
    void DFS(const auto start_vertex);
    void add_edge(const auto v1,const  auto v2,const  auto weight);
    void print_edges();
};

Graph::Graph(const auto vertices)
{
    this->vertices = vertices;
    this->size = vertices + 1;
    this->adj_list = vector<lii>(size);
    cout << "Graph initialized with " << vertices << " vertices \n";
}

void Graph::BFS(const auto start_vertex)
{
    bool visited[size] = {0};
    queue<int> q;
    q.push(start_vertex);

    cout << "\nBFS for the graph is as follows" << endl;
    while(!q.empty())
    {
        auto vertex = q.front(); q.pop();
        visited[size] = true;
        cout << vertex << " ";

        for(auto &i : adj_list[vertex])
        {
            if(visited[i.first] ==  false)
                q.push(i.first);

        }
    }
}

void Graph::DFS(const auto start_vertex)
{
    bool visited[size] = {false};
    stack<int> stk;
    stk.push(start_vertex);
    cout << "\nDFS for the graph is as follows" << endl;

    while(!stk.empty())
    {
        auto node = stk.top(); stk.pop();
        visited[node] = true;
        cout << node << " ";

        for(auto &i : adj_list[node]) {
            if (visited[i.first] == false)
                stk.push(i.first);
        }
    }

}

void Graph::add_edge(const auto v1, const auto v2, const auto weight)
{
    adj_list[v1].push_back(make_pair(v2, weight));
}

void Graph::print_edges()
{
    cout << "List of edges in graph\n";
    for(auto j = 0; j <= vertices; j++)
        for (auto &i : adj_list[j])
        {
            cout << "Edge:"<< j << "->" << i.first << "  Weight:" << i.second << '\n';
        }
}

int main()
{
    int vertices = 0, edges = 0, start_vertex = 0;
    cout << "Enter number of vertices :";
    cin >> vertices;

    Graph g(vertices);

    //vector<list <pair <int,int> > > adj_list(vertices + 1); // Indexing starts from 1
    cout << "Enter number of edges in the graph :";
    cin >> edges;

    cout << "Enter the vertices in format v1 , v2 , w (v1->v2 with weight w)\n";
    for(auto i = 0; i < edges; i++)
    {
        int v1, v2, weight;
        cin >> v1; cin >> v2 ; cin >> weight;
        g.add_edge(v1, v2, weight);
    }

    g.print_edges();
    cout << "Input start vertex for the traversal";
    cin >> start_vertex;
    g.BFS(start_vertex);
    g.DFS(start_vertex);
}
