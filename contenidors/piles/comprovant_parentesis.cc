#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string p;
    while (cin >> p) {
        stack<char> pila;
        bool cap_errada = true;
        for (int i = p.size() - 1; (i >= 0) and (cap_errada); --i) {
            if (p[i] == ')' or p[i] == ']') //recorrem la paraula per anar fent pushback en la pila
            {
                pila.push(p[i]);
            } else if (p[i] == '(') {
                if (not pila.empty()) {
                    cap_errada = (pila.top() == ')');
                    pila.pop();
                } else {
                    cap_errada = false;
                }
            } else {
                if (not pila.empty()) {
                    cap_errada = (pila.top() == ']');
                    pila.pop();
                } else {
                    cap_errada = false;
                }
            }
        }
        //comprovem que la pila no sigui buida
        cout << p;
        if ((cap_errada) and (pila.empty())) {
            cout << " es correcta" << endl;
        } else {
            cout << " es incorrecta" << endl;
        }
    }
}
