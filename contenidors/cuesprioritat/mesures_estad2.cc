#include <iostream>
#include <queue>
#include <string>

using namespace std;

void escriu_mesures(const priority_queue<int, vector<int>, greater<int>>& dades, const int& maxim, const double& suma)
{
    cout.setf(ios::fixed);
    cout.precision(4); //fixem la mida de la mantissa
    cout << "minimum: " << dades.top() << ", "
         << "maximum: " << maxim << ", "
         << "average: " << (suma / dades.size()) << endl;
}

int main()
{
    priority_queue<int, vector<int>, greater<int>> dades; //declarem la cua de prioritat d'aquesta manera per tal que ens ordeni les dades de petit a gran no al reves
    string paraula;
    int maxim;
    double suma = 0;
    while (cin >> paraula) {
        if (paraula == "number") {
            int x;
            cin >> x;
            if (dades.empty() or x > maxim) maxim = x;
            dades.push(x);
            suma += x;
        } else if ((paraula == "delete") and (not dades.empty())) {
            suma -= dades.top(); //eliminem el valor inferior de la suma total
            dades.pop();
        }
        if (dades.empty()) cout << "no elements" << endl;
        else escriu_mesures(dades, maxim, suma);
    }
}
