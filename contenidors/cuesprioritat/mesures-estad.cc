#include <iostream>
#include <queue>
#include <string>

using namespace std;

void troba_mesures(int& maxim, int& minim, double& mitjana, priority_queue<int>& dades, priority_queue<int>& cop_dades)
{
    maxim = dades.top(); //guardem el valor maxim
    cop_dades.push(maxim); //el copiem a l'altra cua
    int mida = dades.size();
    if (mida == 1) {
        mitjana = maxim;
        minim = maxim;
    } else {
        mitjana += maxim;
        dades.pop();
        for (int i = mida; i > 1; --i) {
            int n = dades.top();
            mitjana += n;
            cop_dades.push(n);
            dades.pop();
        }
        minim = dades.top();
        mitjana /= mida;
    }
}
void elimina_minim(int size, priority_queue<int>& dades, priority_queue<int>& dades_menys_petit)
{
    for (int i = size; i > 1; --i) { //copiem les dades a una altre pila excepte la ultima que es la que volem eliminar
        dades_menys_petit.push(dades.top());
        dades.pop();
    }
}

int main()
{
    cout.setf(ios::fixed);
    cout.precision(4); //fixem la mida de la mantissa
    priority_queue<int> dades;
    string paraula;
    while (cin >> paraula) {
        int maxim = 0, minim = 0;
        double mitjana = 0;
        priority_queue<int> cop_dades;
        if (paraula == "number") {
            int x;
            cin >> x;
            dades.push(x);
            troba_mesures(maxim, minim, mitjana, dades, cop_dades);
            cout << "minimum: " << minim << ", maximum: " << maxim << ", average: " << mitjana << endl;
        } else {
            int size = dades.size();
            if (size > 1) {
                priority_queue<int> dades_menys_petit;
                elimina_minim(size, dades, dades_menys_petit);
                troba_mesures(maxim, minim, mitjana, dades_menys_petit, cop_dades);
                cout << "minimum: " << minim << ", maximum: " << maxim << ", average: " << mitjana << endl;
            } else {
                if (size == 1) //funciona pel cas que la mida sigui 1 o 0
                    dades.pop();
                cout << "no elements" << endl;
            }
        }
        dades = cop_dades;
    }
}
