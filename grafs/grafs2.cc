#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>

using namespace std;
using Node = string;
using Graph = vector<vector<Node>>;

Graph read_graph(map<Node, int>& connections){
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i){
    Node city;
    cin >> city;
    connections[city] = i;
  }
  //the info about the position in which teh cities will be stores is saved in the connections map

  int m;
  cin >> m;
  Graph G(n);
  for(int j = 0; j < m; ++j){
    string city1, city2;
    cin >> city1 >> city2;
    G[connections[city1]].push_back(city2);
  }
  return G;
}

//boolean that returns whether if it exists a path between two nodes
bool path_exists(const Graph& G, map<Node, int>& connections, Node start, Node dest){
  stack<string> s;
  s.push(start);
  vector<bool> visited(G.size());
  while(not s.empty()){
    string element = s.top();
    s.pop();
    if(element == dest) return true;
    for(const Node& v : G[connections[element]]){
      if(not visited[connections[v]]){
        //variable x is the position in where we have to search in the big vector
        //wherean i is for the list index
        s.push(v);
      //we go across the list of a node and add it to the stack
        visited[connections[v]] = true;
      }
    }
  }
  return false;
}

int main(){
  map<Node, int> connections;
  Graph G = read_graph(connections);
  Node start, dest;
  cin >> start >> dest;
  cout << (path_exists(G, connections, start, dest) ? "yes" : "no") << endl;
}
