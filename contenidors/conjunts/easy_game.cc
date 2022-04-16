#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

bool comparador(const string& a, const string& b)
{
    if (a.size() == b.size())
        return a < b;
    return a.size() < b.size();
}

void crear_vector(vector<string>& v, set<string>& passat)
{
    for (int i = 0; i < v.size(); ++i) {
        auto it = passat.begin();
        v[i] = *it;
        passat.erase(*it);
    }
    sort(v.begin(), v.end(), comparador);
}

void escriu_conjunt(set<string>& actual, set<string>& passat, int& n)
{
    cout << "GAME #" << n << endl
         << "HAS:" << endl;
    auto it = actual.begin();
    while (it != actual.end()) {
        cout << *it << endl;
        actual.erase(*it);
        it = actual.begin();
    }
    cout << endl
         << "HAD:" << endl;
    vector<string> v(passat.size());
    crear_vector(v, passat);
    for (string e : v) {
        cout << e << endl;
    }
    ++n;
}

void modifica_conjunts(set<string>& actual, set<string>& passat, const string& w)
{
    auto it = actual.find(w);
    if (it == actual.end()) //cas en que no hem trobat la paraula
    {
        auto it_q = passat.find(w);
        if (it_q != passat.end()) { //hem tobat la paraula al conjunt de paraules que ja havien estat abans
            passat.erase(*it_q);
        }
        actual.insert(w);

    } else //hem trobat que la paraula esta en el conjunt
    {
        actual.erase(w);
        passat.insert(w);
    }
}

int main()
{
    string w;
    int n = 1;
    set<string> actual;
    set<string> passat;
    bool primer = true;
    while (cin >> w and w != "QUIT") {
        if (w == "END") {
            if (not primer)
                cout << endl;
            primer = false;
            escriu_conjunt(actual, passat, n);

        } else {
            modifica_conjunts(actual, passat, w);
        }
    }
    escriu_conjunt(actual, passat, n);
}
