#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;
/* Action that given a map and a set writes them  */
void write_affairs(const map<string, string>& taken, const set<string>& alone)
{
    cout << "COUPLES:" << endl; //bucle to write all couples
    for (const auto& e : taken) if(e.first < e.second) cout << e.first << ' ' << e.second << endl;
    cout << "ALONE:" << endl;
    for (const auto& u: alone) cout << u << endl;
    cout << "----------" << endl;
}


void update_affairs(map<string, string>& taken, set<string>& alone)
{
    string x, y;
    cin >> x >> y;

    if(taken.count(x)) alone.insert(taken[x]); //in case x was found, its couple goes alone
    if(taken.count(y)) alone.insert(taken[y]);
    taken.erase(taken[x]);
    taken.erase(taken[y]);
    taken[x] = y; //by doing this we are reasingning the info of the key x, and in case
    //it doesn't exist, we create a new element in the dictionary with x as key and y as info
    taken[y] = x;
    alone.erase(x);
    alone.erase(y);
}



int main()
{
    string order;
    map<string, string> taken;
    set<string> alone;
    while (cin >> order) {
        if (order == "affair") update_affairs(taken, alone);
        else write_affairs(taken, alone);
    }
}
