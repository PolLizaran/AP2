#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

struct participants{
  string name;
  int points;
};

//action that given a player disconnects it from the server in case it was already in it.
void logout(map<string, int>& server, map<string, int>& out_server){
  string player1;
  cin >> player1;
  auto it = server.find(player1);
  if (it != server.end()){
    out_server.insert({ it->first, it->second }); //maybe brokes
    server.erase( it->first );
  }
}

void play(map<string, int>& server){
  string player1, player2;
  cin >> player1 >> player2;
  if(not server.count(player1) or not server.count(player2)) cout << "player(s) not connected" << endl;
  else{
    server[player1] += 10; //we add 10 elo points to the winner
    if(server[player2] != 1200) server[player2] -= 10; //check if the player has the lowest legal points and ther substract
  }
}

void get_elo(map<string, int>& server, map<string, int>& out_server){
  string player1;
  cin >> player1;
  if (server.count(player1)) cout << player1 << ' ' << server[player1] <<endl;
  else cout << player1 << ' ' << out_server[player1] << endl;
}

void read_actions(map<string, int>& server, map<string, int>& out_server, string s){
  if (s == "LOGIN"){
    string player1;
    cin >> player1;
    if (not server.count(player1)){
      auto it = out_server.find(player1);
      if (it != out_server.end()){
        server.insert({it->first, it->second});
      }else server.insert({player1, 1200});
    }
    out_server.erase(player1);
  }
  else if (s == "LOGOUT") logout(server, out_server);
  else if (s == "PLAY") play(server);
  else if(s == "GET_ELO") get_elo(server, out_server);
}

//action that sorts the players in terms of their elos
bool conditions(const participants& a, const participants& b){
  if(a.points == b.points) return a.name < b.name;
  return a.points > b.points;
}

void write_ranking(map<string, int>& server,map<string, int>& out_server){
  cout << endl
       << "RANKING" << endl;
  vector<participants> ranking;
  for(auto p = server.begin(); p != server.end(); ++p) ranking.push_back({p->first, p->second});
  for(auto j = out_server.begin(); j != out_server.end(); ++j) ranking.push_back({j->first, j->second});
  sort(ranking.begin(), ranking.end(), conditions);
  for(participants p : ranking) cout << p.name << ' ' << p.points << endl;

}

int main(){
  map<string, int> server;
  map<string, int> out_server; //map used to store the info of players that are no longer connected
  string s;
  while(cin >> s){
    read_actions(server, out_server, s);
  }
  write_ranking(server, out_server);
}
