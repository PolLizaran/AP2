#include <iostream>
#include <map>
#include <string>
using namespace std;

void escriu_min_max(map<string, int>& m, string extrem, string p, int n)
{
    if (m.empty()) {
        cout << "indefinite " << extrem << endl;
    } else {
        cout << extrem << ": " << p << ", " << n << " time(s)" << endl;
    }
}

int main()
{
    string s;
    map<string, int> m;
    while (cin >> s) {
        string word;
        if (s == "store") {
            cin >> word;
            auto it = m.find(word);
            if (it == m.end()) {
                m.insert({ word, 1 });
            } else {
                ++it->second;
            }
        } else if (s == "delete") {
            cin >> word;
            auto it = m.find(word);
            if (it != m.end()) {
                if (it->second != 1)
                    --it->second;
                else
                    m.erase({ word });
            }

        } else {
            if (s == "minimum?") {
                auto it = m.end();
                if (m.size() <= 1) {
                    it = m.begin();
                } else {
                    --it;
                }
                escriu_min_max(m, "minimum", *it->first, *it->second);
            } else {
                auto it = m.begin();
                escriu_min_max(m, "maximum", *it->first, *it->second);
            }
        }
    }
}
