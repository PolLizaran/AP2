#include <iostream>
#include <vector>

using namespace std;

bool can_drive(const vector<int>& v, int stops, int current){
  int sum = 0;
  int n_stops = 0;
  for(int i = 0; i < v.size(); ++i){
    if(v[i] > current) return false; //no t
    sum += v[i];
    if(sum > current){
      ++n_stops;
      sum = v[i];
    }
  }
  if(n_stops > stops) return false;
  return true;
}


//donat un vector , el nombre maxim de parades que podem fer i la suma total de totes les distancies
//volem calcular quant ha de tenir de capacitat el diposit per poder recorrer es carreteres

int autonomy(vector<int> v, int stops, int min_autonomy, int max_autonomy){
  int current = (min_autonomy + max_autonomy) / 2;
  if(min_autonomy == max_autonomy){
    return current;

  //donada la meitat, en cas que puguem conduir, hem de mirar per les posicions inferiors
  }else if (can_drive(v, stops, current)){
      return autonomy(v, stops, min_autonomy, current);
  } else{
      return autonomy(v, stops, current + 1, max_autonomy);
  }
}


void read_vector_total(vector<int>& v, int& total){
  for(int i = 0; i < v.size(); ++i){
    cin >> v[i];
    total += v[i];
  }
}


int main(){
  int cities, stops;
  while(cin >> cities >> stops){
    vector <int> v(cities);
    int total = 0;
    read_vector_total(v, total);
    cout << autonomy(v, stops, 0, total) << endl;
  }
}
