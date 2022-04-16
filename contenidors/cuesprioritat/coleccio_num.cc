#include <iostream>
#include <queue>
using namespace std;

//creem una acció que passat un caracter ens faci les operacions corresponents
void executa(priority_queue<int>& p, char c)
{
    int x;
    if (c == 'S') {
        cin >> x;
        p.push(x);
    } else if (c == 'A')
        (p.empty() ? cout << "error!" << endl : cout << p.top() << endl);
    else if (c == 'R')
        if (p.empty())
            cout << "error!" << endl;
        else
            p.pop();
    else {
        cin >> x;
        if (p.empty())
            cout << "error!" << endl;
        else {
            int y = p.top();
            p.pop();
            if (c == 'I') {
                p.push((y + x));
            } else if (c == 'D')
                p.push(y - x);
        }
    }
}

int main()
{
    char c;
    priority_queue<int> p;
    while (cin >> c) {
        executa(p, c);
    }
}
