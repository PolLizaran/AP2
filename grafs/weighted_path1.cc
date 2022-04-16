#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int Infinite = 1000000;

struct edge{
  int dest;
  int cost;
};

using arc = vector<edge>;
using Graph = vector<arc>;

bool operator< (const edge& a, const edge& b){
  return a.cost > b.cost;
}

bool read_edges(Graph& G){
  int n, m;
  if(not (cin >> n >> m)){
    return false;
  }
  G = Graph(n);
  for(int i = 0; i < m; ++i){
    int beg, dest, cost;
    cin >> beg >> dest >> cost;
    G[beg].push_back({dest, cost});
  }
  return true;
}



//works as a DFS but this time instead of having just integers, we have a cost associated to going from
//one edge to another
void dijkstra(const Graph& G, const int& x, const int& y, vector<int>& dist){
  int n = G.size();
  dist = vector<int> (n, Infinite);
  dist[x] = 0;

  priority_queue<edge> pq; //first to store distance and the second for the destiny
  pq.push({x, 0});

  vector<bool> visited(n, false);
  while(not pq.empty()){
    int u = pq.top().dest;
    if (u == y) return;
    pq.pop();
    if(not visited[u]){
      visited[u] = true;
      for(const edge& a : G[u]){
        int v = a.dest, c = a.cost;
        if(dist[v] > dist[u] + c){
          dist[v] = dist[u] + c;
          pq.push({v, dist[v]});
        }
      }
    }
  }
}


int main(){
  Graph G;
  while(read_edges(G)){
    int x, y;
    cin >> x >> y;
    vector<int> dist;//at the beginning distances must be infinite
    dijkstra(G, x, y, dist);
    if (dist[y] == Infinite) cout << "no path from " << x << " to " << y << endl;
    else cout << dist[y] << endl;
  }
}
