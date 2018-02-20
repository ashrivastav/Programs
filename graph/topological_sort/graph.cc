#include <iostream>
#include <list>
#include <vector>
#include <thread>
#include <future>
#include <stack>
#include <unistd.h>
#include <queue>
using namespace std;

class Graph {
public:
  int vertices;
  list<int> *adj;
  Graph(int v):vertices(v) {
    adj = new list<int>[v];
  }
  void add_edge(int u, int v) {
    adj[u].push_back(v);
  }
  static int worker(int time);
  void print_graph(); 
  void topological_sort();
  
  /* Recursive way of topological sort */
  stack<int> result;
  void topological_sort_v1();
  void topological_sort_v1_helper(int, vector<bool>&);
};

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
int Graph::worker(int seconds)
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
  int indegree[vertices];
  
  for (int i = 1; i < vertices ;i++)
  {
    indegree[i] = 0;
  }

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
      pending++;
    }
  }

  cout << "Topological Sorting is ";
  list< future<int> > pending_task;
  while(!q.empty() || pending)
  {
    if (!q.empty()) {
      auto vertex = q.front();
      q.pop();
      pending_task.push_back(async(std::launch::async, &Graph::worker, vertex));
    }

    for (auto &i : pending_task)
    {
      int completed_task;
      if (i.valid() == true && i.wait_for(chrono::seconds(0)) == future_status::ready &&
          (completed_task = i.get())) {
        pending--;
        for (auto &j : adj[completed_task])
        {
          indegree[j]--; 
          if(indegree[j] == 0){
            q.push(j);
            pending++;
          }
        }
      }

    }
}
}

void Graph::topological_sort_v1_helper(int vertex, vector<bool>& visited)
{
  visited[vertex] = true;

  for(auto &i : adj[vertex])
  {
    if (visited[i] == false)
      topolocial_sort_v1_helper(i, visited);
  }

  result.push(i);
}

void Graph::topological_sort_v1()
{
  vector<bool> visited(vertices+1,false);
  for(int i =1; i < (vertices +1) ; i++)
  {
    if (visited[i] == false)
      topological_sort_v1_helper(i, visited);
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
  Graph g(vertices + 1);
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
  g.topological_sort_v1(); //recursive
}
