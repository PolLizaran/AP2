#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    string name;
    map<string, int> stats;
    while (cin >> name) {
        string s;
        cin >> s;
        //entrada al casino
        auto it = stats.find(name);
        if (s == "enters") {
            if (it == stats.end()) {
                stats.insert({ name, 0 });
            } else {
                cout << name << " is already in the casino" << endl;
            }
            //sortida del casino
        } else if (s == "leaves") {
            if (it == stats.end()) {
                cout << name << " is not in the casino" << endl;
            } else {
                cout << name << " has won " << it->second << endl;
                stats.erase(name);
            }
        } else {
            //guanya x diners
            int x;
            cin >> x;
            if (it == stats.end()) {
                cout << name << " is not in the casino" << endl;
            } else {
                it->second += x;
            }
        }
    }
    cout << "----------" << endl;
    for (auto e : stats) {
        cout << e.first << " is winning " << e.second << endl;
    }
}
