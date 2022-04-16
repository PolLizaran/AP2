#include <iostream>
#include <set>
#include <stack>
#include <string>
using namespace std;

void deixa_joia(set<int>& bossa, set<int>& tresor, int n, long x, long& total)
{
    //comprovem si la joia esta entre es que tenen mes valor
    if (bossa.empty() or (bossa.size() < n)) {
        total += x;
        bossa.insert(x);
    } else {
        if (*bossa.begin() < x) {
            total -= (*bossa.begin());
            total += x;
            tresor.insert(*bossa.begin());
            bossa.erase(*bossa.begin());
            bossa.insert(x);
        } else {
            tresor.insert(x);
        }
    }
}

void treu_joia(set<int>& bossa, set<int>& tresor, int n, long x, long& total)
{
    if (bossa.count(x) != 0) {
        //borrem l'element contingut a la bossa i afegim el de més valor del tresor
        bossa.erase(x);
        total -= x;
        if (not tresor.empty()) {
            long max = *--tresor.end();
            tresor.erase(max);
            total += max;
            bossa.insert(max);
        }
    } else {
        //cas en que la joia treta no estava a la bossa
        tresor.erase(x);
    }
}
int main()
{
    int n;
    cin >> n;
    string s;
    set<int> bossa;
    set<int> tresor;
    long total = 0;
    while (cin >> s) {
        long x;
        cin >> x;
        if (s == "deixar") {
            deixa_joia(bossa, tresor, n, x, total);
        } else if (s == "endur") {
            treu_joia(bossa, tresor, n, x, total);
        }
        cout << total << endl;
    }
}
