#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;


void receives(map<string, int>& earnings){
    string name;
    int x;
    cin >> name >> x;
    if(earnings.count(name)) earnings[name] = earnings[name] + x;
    else earnings.insert({name, x});
}

void gives(map<string, int>& earnings){
    string name;
    int x;
    cin >> name >> x;
    if(earnings.count(name)) earnings[name] = earnings[name] - x;
    else earnings.insert({name, - x});
}

void pays(map<string, int>& earnings){
    string name1, name2;
    int x;
    cin >> name1 >> x >> name2;
    if(earnings.count(name1)) earnings[name1] = earnings[name1] - x;
    else earnings.insert({name1, - x});
    if(earnings.count(name2)) earnings[name2] = earnings[name2] + x;
    else earnings.insert({name2, x});
}

/*R name number: Politician name receives number money (from some unknown bank).
G name number: Politician name gives number money (to some unknown relative).
P name1 number name2: Politician name1 pays number money to politician name2, where name1 and name2 are different.*/
void read_and_apply_transactions(map<string, int>& earnings){
    string kind;
    while(cin >> kind and kind != "END"){
        if(kind == "R") receives(earnings);
        else if(kind == "G") gives(earnings);
        else if(kind == "P") pays(earnings);
    }
}

void print_transactions(int r, map<string, int>& earnings){
    vector<pair<string, int>> v;
    for(pair<string, int> k : earnings){
        v.push_back(k);
    }
    int number_iterations = earnings.size();
    int elements_per_row = number_iterations / r;
    if(number_iterations % r != 0) ++elements_per_row;
    int current_pos = 0;
    int k = 1;
    int row_counter = elements_per_row;
    string info = "";
    while(number_iterations--){
        if(not info.empty()) info += " | ";
        info = info + v[current_pos].first + " " + to_string(v[current_pos].second);
        current_pos += elements_per_row;
        --row_counter;
        if(row_counter == 0){
            cout << info << endl;
            current_pos = k;
            ++k;
            row_counter = elements_per_row;
            info = "";
        }
    }
        cout <<"****************************************" << endl;
}


int main(){
    int r;
    while (cin >> r){
        map<string, int> earnings;
        read_and_apply_transactions(earnings);
        print_transactions(r, earnings);
    }
}
