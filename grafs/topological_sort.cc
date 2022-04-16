#include <iostream>
#include <vector>

using namespace std;
using Nodes = int;
using List = vector<Nodes>
using AdjList = vector<List>;

AdjList read_nodes(){
  int n, m;
  cin >> n >> m;
  AdjList G vector<Nodes>(n);
  int x, y;
  for(int i = 0; i < m; ++i){
    cin >> x >> y;
    G[x].push_back(y);
  }
  return G;
}


int main(){

  AdjList G = read_nodes();
}
