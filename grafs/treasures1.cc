#include <iostream>
#include <vector>
#include <stack>

using namespace std;
using map = vector<vector<char>>;
using visit_map = vector<vector<bool>>;

struct point{
  int x;
  int y;
};

/* this way isn't faster
int convert_char_to_number(const char& c){
  if(c == '.') return 0;
  if(c == 'X') return -1;
  if(c == 't') return 1;
}*/

//we create the map
map read_map(){
  int n, m;
  cin >> n >> m;
  map M(n, vector<char>(m));
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      cin >> M[i][j];
      //M[i][j] = convert_char_to_number(c);
    }
  }
  return M;
}

//vector that given a point, returns a vectors with it's neighbours
 vector<point> neighbour(const point& s, const int& row_len, const int& col_len){
  int x = s.x;
  int y = s.y;
  vector<point> v;
  if(x > 0) v.push_back({x - 1, y});
  if(x < row_len - 1) v.push_back({x + 1, y});
  if(y > 0) v.push_back({x, y - 1});
  if(y < col_len - 1) v.push_back({x, y + 1});
  return v;
}

//returns true in case we can find a treasure
bool can_reach(const map& M, const point& p){
  stack<point> positions;
  positions.push(p);
  visit_map visited(M.size(), vector<bool>(M[0].size(), false));
  while(not positions.empty()){
    point s = positions.top();
    positions.pop();
    if(M[s.x][s.y] == 't') return true; //means there is a treasure there
    int row_len = visited.size();
    int col_len = visited[0].size();
    vector<point> v = neighbour(s, row_len, col_len);
    //vector where we store the neighbours and in case they aren't 'X' (obstacle), we push them into the stack
    for(int i = 0; i < v.size(); ++i){
      if(not visited[v[i].x][v[i].y] and M[v[i].x][v[i].y] != 'X'){
        positions.push({v[i].x, v[i].y}); //this push will be a position from a '.' or 't'
        visited[v[i].x][v[i].y] = true;
      }
    }
  }
  return false;
}

int main(){
  map M = read_map();
  int r, c;
  cin >> r >> c;
  cout << (can_reach(M, {r - 1, c - 1}) ? "yes" : "no") << endl;
}
