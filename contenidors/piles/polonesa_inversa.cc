#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    stack<int> pila;
    string p;
    while (cin >> p) {
        if (p.size() > 1) {
            int x = p[0] - '0';
            for (int i = 1; i < p.size(); ++i) { //aquest bucle el podriem fer amb la funció stoi (string to integer)
                x = x * 10 + (p[i] - '0');
            }
            pila.push(x);
        } else {
            char c = p[0];
            if (isdigit(c)) {
                pila.push(c - '0');
            } else {
                int y = pila.top();
                pila.pop();
                int z = pila.top();
                pila.pop();
                if (c == '+') {
                    pila.push(z + y);
                } else if (c == '-') {
                    pila.push(z - y);
                } else if (c == '*') {
                    pila.push(z * y);
                }
            }
        }
    }

    stack<int> p2;
    for (int i = pila.size(); i > 0; --i) {
        p2.push(pila.top());
        pila.pop();
    }
    for (int j = p2.size(); j > 0; --j) {
        cout << p2.top() << endl;
        p2.pop();
    }
}
