#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int Infinite = 100000;
int Nil = -1;

struct Edge{
  int dest; //destiny
  int weight; //weight of the path of going to dest;
};

using Arc = vector<Edge>;
using Graph = vector<Arc>;

bool operator< (const Edge& a, const Edge& b){
  return a.weight > b.weight;
}

bool read_graph(Graph& G){
  int n, m;
  if(not (cin >> n >> m)) return false;
  G = Graph(n);
  for(int i = 0; i < m; ++i){
    int beg, dest, cost;
    cin >> beg >> dest >> cost;
    G[beg].push_back({dest, cost});
  }
  return true;
}

void dijkstra(const Graph& G, vector<int>& cost, const int& x, const int& y, vector<int>& prev){
  int n = G.size();
  vector<bool> visited(n, false);

  prev = vector<int>(n, Nil); // vector where we store the predecessors of each Node

  cost = vector<int>(n, Infinite);
  cost[x] = 0;

  priority_queue<Edge> pq; //we initialize a priority queue empty and it will be the place where we'll store Edges
  pq.push({x, 0}); // we add the first vertex to the queue
  while(not pq.empty()){
    int u = pq.top().dest;
    if(u == y) return; //means we've reached our objective
    pq.pop();
    if(not visited[u]){
      visited[u] = true;

      for(const Edge a : G[u]){
        int v = a.dest, c = a.weight;

        if(cost[v] > cost [u] + c){
          cost[v] = cost [u] + c;
          prev[v] = u;
          pq.push({v, cost[v]});
        }
      }
    }
  }
}

//action that stores in a stack the cheapest path to follow once we've done dijkstra
void write_path_min_cost(const Graph& G, const int& x, const int& y, const vector<int>& prev){
  int a = y;
  stack<int> path;
  path.push(a);
  while(prev[a] != Nil){ //while we doesn't reach a Nil, it means that we are still in the path
  //it can't be possible that longer paths going far from x exist, as we start at x ant its prev is NIL
    path.push(prev[a]);
    a = prev[a];
  }

  cout << path.top();
  path.pop();
  while(not path.empty()){
    cout << ' ' << path.top();
    path.pop();
  }
  cout << endl;
}

int main(){
  Graph G;
  while(read_graph(G)){
    int x, y;
    cin >> x >> y;
    vector<int> prev;
    vector<int> cost;
    dijkstra(G, cost, x, y, prev);
    if(cost[y] != Infinite){
      write_path_min_cost(G, x, y, prev);
    } else cout << "no path from " << x << " to " << y << endl;
  }
}
