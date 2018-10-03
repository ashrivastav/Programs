#include <iostream>
#include <list>
#include <vector>
#include <thread>
#include <future>
#include <stack>
#include <unistd.h>
#include <queue>
using namespace std;

/* Directed Graph for Topological Sort */
class Graph {
private:
  int vertices;
  vector<int> *adj;
public:
  Graph(int v):vertices(v + 1) {
    adj = new vector<int>[v];
  }

  void add_edge(int u, int v) {
    adj[u].push_back(v);
  }

  void print_graph(); 
  void topological_sort();
  
  /* Recursive way of topological sort */
  stack<int> result;
  void topological_sort_recursive();
  void topological_sort_helper(int, vector<bool>&);
};

int worker(int time);

void Graph::print_graph()
{
  cout << "Printing Graph edges" << endl;
  for(int i=1 ; i < vertices ; i++)
  {
    for (auto j : adj[i])
    {
      cout <<  i << "-->"  << j << endl;
    } 
  }
}

/* Task number is number of seconds to wait */
int worker(int seconds)
{
  cout << "\nTask for " << seconds << " seconds started\n" ;
  sleep(seconds);
  cout << "\nTask completed in " << seconds << "seconds\n";
  return seconds;
}

void Graph::topological_sort()
{
  queue<int> q; // Queue for adding next zero indegree node

  int pending = 0;
  vector<int> indegree(vertices, 0); //vector of indegree for all vertices 
                                     //initialized to zero
 
  for(int i=1 ; i < vertices ; i++)
  {
    for (auto &j : adj[i])
    {
      indegree[j]++; 
    } 
  }

  for (int i =1 ; i< vertices; i++) {
    cout << "Indegree for vertex " << i << "is" << indegree[i] << endl;
    if(indegree[i] == 0) {
      q.push(i);
    }
  }

  cout << "Topological Sorting is ";
  list< future<int> > pending_task;
  while(!q.empty() || pending)
  {
    if (!q.empty()) {
      int vertex = q.front();
      q.pop();
      pending_task.push_back(async(std::launch::async, worker, vertex));
      pending++;
    }

    for (auto &fut : pending_task)
    {
      int completed_task;
      if (fut.valid() == true && 
          fut.wait_for(chrono::seconds(0)) == future_status::ready &&
          (completed_task = fut.get())) 
      {
        pending--;

        for (auto &j : adj[completed_task])
        {
          indegree[j]--; 
          if(indegree[j] == 0)
            q.push(j);   
        }
      }
    }
}
}

void Graph::topological_sort_helper(int vertex, vector<bool>& visited)
{
  visited[vertex] = true;

  for(auto &i : adj[vertex])
  {
    if (visited[i] == false)
      topological_sort_helper(i, visited);
  }

  result.push(vertex);
}

void Graph::topological_sort_recursive()
{
  vector<bool> visited(vertices+1,false);

  for(int i =1; i < (vertices +1) ; i++)
  {
    if (visited[i] == false)
      topological_sort_helper(i, visited);
  }

  cout << "Topolocial sort is";
  while(!result.empty()){
    cout << result.top() <<" " ;
    result.pop();
  }
}

int main()
{
  int vertices, edges;
  cout.sync_with_stdio(true);
  cout << "Provide number of vertices in graph";
  cin >> vertices;
  Graph g(vertices);
  cout << "Number of edges in graph";
  cin >> edges;

  for (auto i = 0; i < edges; i++)
  {
    int u, v;
    cin >> u;
    cin >> v;
    g.add_edge(u,v);
  }
  g.print_graph();
  g.topological_sort();
  //g.topological_sort_recursive(); //recursive
}
