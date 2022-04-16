#include <iostream>
#include <map>
#include <string>
using namespace std;

void escriu_min_max(map<string, int>& m, string extrem)
{
    map<string, int>::iterator it;
    if (extrem == "maximum") {
        it = m.end();
        --it;
    } else it = m.begin();
    cout << extrem << ": " << it->first << ", " << it->second << " time(s)" << endl;
}

void store(map<string, int>& m)
{
    string word;
    cin >> word;
    map<string, int>::iterator it = m.find(word);
    if (it == m.end()) m.insert({ word, 1 });
    else ++it->second;
}

void remove(map<string, int>& m)
{
    string word;
    cin >> word;
    map<string, int>::iterator it = m.find(word);
    if (it != m.end()) --it->second;
    if (it->second == 0) m.erase(word);
}

int main()
{
    string s;
    map<string, int> m;
    while (cin >> s) {
        if (s == "store") store(m);
        else if (s == "delete") remove(m);
        else {
            if (s == "minimum?") s = "minimum";
            else s = "maximum";
            if (m.empty()) cout << "indefinite " << s << endl;
            else escriu_min_max(m, s);
        }
    }
}
