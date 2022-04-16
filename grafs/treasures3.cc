#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cmath>

using namespace std;
using Node = char;
using map = vector<vector<Node>>;
using vis = vector<vector<bool>>;

struct point{
  int x;
  int y;
};

//we create the map
map read_map(){
  int n, m;
  cin >> n >> m;
  map M(n, vector<Node>(m));
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      cin >> M[i][j];
    }
  }
  return M;
}

//vector that given a point, returns a vectors with it's neighbours
 vector<point> neighbour(const point& s, const int& n, const int& m){
  int x = s.x;
  int y = s.y;
  vector<point> v;
  if(x > 0) v.push_back({x - 1, y});
  if(x < n - 1) v.push_back({x + 1, y}); //not the last row
  if(y > 0) v.push_back({x, y - 1});
  if(y < m - 1) v.push_back({x, y + 1}); //not the last column
  return v;
}

//returns true i case we can find a treasure. To make this implementation, we'll use a queue as we want
//to make a breath first search instead of a depth first search
int n_treasures_can_reach(const map& M, const point& p){
  int n = M.size();
  int m = M[0].size();
  queue<point> positions;
  positions.push(p);
  vis visited(n, vector<bool>(m));

  //the minus 1 simulates an infinite distance that hasn't been computed yet
  visited[p.x][p.y] = true; //the start has distance 0
  int number_treasures = 0;
  while(not positions.empty()){
    point s = positions.front();
    positions.pop();
    for(point u : neighbour(s, n, m)){//vector where we store the neighbours and in case they aren't 'X' (obstacle), we push them into the stack
      if(not visited[u.x][u.y] and M[u.x][u.y] != 'X'){
        if(M[u.x][u.y] == 't') ++number_treasures;
        visited[u.x][u.y] = true;
        positions.push({u.x, u.y}); //this push will be a position from a '.' or 't'
      }
    }
  }
  return number_treasures;
}

int main(){
  map M = read_map();
  int r, c;
  cin >> r >> c;
  cout << n_treasures_can_reach(M, {r - 1, c - 1}) << endl;
}
