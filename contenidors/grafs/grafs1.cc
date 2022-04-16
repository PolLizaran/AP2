#include <iostream>
#include <vector>
#include <stack>
using namespace std;

using connections = vector<int>;
using Graph = vector<connections>;

void read_arcs(Graph& G, int m){
  int x, y;
  for(int i = 0; i < m; ++i){
    cin >> x >> y;
    G[x].push_back(y);
  }
}
/*
void print_graf(const Graph& G){
  for (int i = 0; i < G.size(); ++i){
    for (auto it = G[i].begin(); it != G[i].end(); ++it)
      cout << "node " <<i << ':' << *it << endl;
  }
}
*/

/* Boolean function that determines if there is a path that connects x with y. To do it, we will use
an iterative algorithm with the aid of a stack. We start from the node x and add to the stack all the
subyacent arcs. By each of them, we do the same. By this we can achieve to look over all the nodes
connected to the first one. When we get across a new node that wasn't treated we turn the correspondent
position of the visited vector into true to assure we don't go over it again. In case an element of the
stack is equal to y, this will mean that a path between x and y exists. */
bool is_arc(const Graph& G){
    int x, y;
    cin >> x >> y;
    stack<int> nodes;
    nodes.push(x);
    vector<bool> visited(G.size());
    while(not nodes.empty()){
      int u = nodes.top();
      nodes.pop();
      if (u == y) return true;
      for(int e: G[u]){
        if(not visited[e]){
          nodes.push(e);
          visited[e] = true;
        }
      }
  }
  return false;
}

int main(){
  int bound, m;
  cin >> bound >> m;
  Graph G(bound);
  read_arcs(G, m);
  //print_graf(G);
  if (is_arc(G)) cout << "yes" << endl;
  else cout << "no" << endl;
}
