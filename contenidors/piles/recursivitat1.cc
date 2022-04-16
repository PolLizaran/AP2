#include <iostream>
#include <stack>
using namespace std;

void work(int n)
{
    stack<int> s;
    s.push(n);
    while (not s.empty()) {
        if (s.top() != 1) {
            int x = s.top();
            s.pop();
            cout << ' ' << x;
            s.push(x - 1);
            s.push(x - 1);
        } else {
            cout << ' ' << s.top();
            s.pop();
        }
    }
}

int main()
{
    int n;
    while (cin >> n) {
        work(n);
        cout << endl;
    }
}
