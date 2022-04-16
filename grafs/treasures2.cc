#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cmath>

using namespace std;
using Node = char;
using map = vector<vector<Node>>;
using dist = vector<vector<int>>;

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
string can_reach(const map& M, const point& p){
  int n = M.size();
  int m = M[0].size();
  queue<point> positions;
  positions.push(p);
  dist distances_t(n, vector<int>(m, -1));
  //the minus 1 simulates an infinite distance that hasn't been computed yet
  distances_t[p.x][p.y] = 0; //the start has distance 0
  while(not positions.empty()){
    point s = positions.front();
    positions.pop();
    vector<point> v = neighbour(s, n, m);
    //vector where we store the neighbours and in case they aren't 'X' (obstacle), we push them into the stack
    for(point u : v){
      if(M[s.x][s.y] == 't'){
        string l = to_string(distances_t[s.x][s.y]);
        return "minimum distance: " + l;//we return the distance that was stores in the vector
      } else if((distances_t[u.x][u.y] == -1) and (M[u.x][u.y] != 'X')){
        positions.push({u.x, u.y}); //this push will be a position from a '.' or 't'
        distances_t[u.x][u.y] = distances_t[s.x][s.y] + 1;
      }
    }
  }
  return "no treasure can be reached";
}

int main(){
  map M = read_map();
  int r, c;
  cin >> r >> c;
  cout << can_reach(M, {r - 1, c - 1}) << endl;
}
