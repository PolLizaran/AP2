#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
    string s;
    set<string> m;
    cin >> s;
    if (s != "END") {
        string mediana = s;
        m.insert(s);
        cout << s << endl;
        set<string>::iterator it = m.begin();
        while (cin >> s and s != "END") {
            m.insert(s);
            if ((m.size() % 2 == 0) and (s < mediana))
                --it;
            if ((m.size() % 2 != 0) and (s > mediana))
                ++it;
            cout << *it << endl;
            mediana = *it;
        }
    }
}
