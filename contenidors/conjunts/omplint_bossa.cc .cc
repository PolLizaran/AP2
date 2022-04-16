#include <iostream>
#include <set>
#include <stack>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    set<int> valor;
    while (cin >> s) {
        int x;
        cin >> x;

        if (s == "deixar") {
            valor.insert(x);
        } else if (s == "endur") {
            valor.erase(x);
        }

        long int total = 0;
        int j = 0;
        for (auto rit = valor.rbegin(); rit != valor.rend() and j < n; ++rit, ++j) {
            //p.push(*it);
            total += *rit;
        }

        cout << total << endl;
    }
}
