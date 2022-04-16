#include <iostream>
#include <vector>

using namespace std;

// Structure to represent a point in a 2D space
struct Point {
    int x, y;
};

// A skyline is a vector of Points sorted by the x coordinate
using Skyline = vector<Point>;

//function that reads a Skyline with its coordinates x, y.
Skyline read_skyline()
{
    int n;
    cin >> n;
    Skyline s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i].x >> s[i].y;
    }
    return s;
}

//Action that prints the skyline s containing the superposition of sky 1 and sky 2
void print_skyline(const Skyline& s)
{
    const int n = s.size();
    cout << n;
    for (int i = 0; i < n; ++i) {
        cout << ' ' << s[i].x << ' ' << s[i].y;
    }
    cout << endl;
}

Skyline skyline_superposition(const Skyline& s1, const Skyline& s2)
/* Given two vectors of points, we do the superposition of them distiguishing 3 posible cases.
To select the x coordinate we always get the lower one and to get the y, the biggest one as will
be the skyline that outweights the other.*/
{
    int height_s1 = -1;
    int height_s2 = -1;
    Skyline result;
    int i = 0, j = 0;
    int x = -1, y = -1;
    while (i < s1.size() and j < s2.size()) {
        if (s1[i].x < s2[j].x) {
            x = s1[i].x;
            height_s1 = s1[i++].y; //we save the height_s1 and then add 1 to i.
        } else if (s2[j].x < s1[i].x) {
            x = s2[j].x;
            height_s2 = s2[j++].y; //we save the height_s2 and then add 1 to j.
        } else {
            x = s1[i].x; //is indiferent which value of x we save as they are equal
            //we have to check which height of the skylines is higher, so we save them in two variables
            height_s1 = s1[i++].y;
            height_s2 = s2[j++].y;
        }

        int maxim = max(height_s1, height_s2);
        if (y != maxim) { //this condition is super mega important as it wouldn't propperly work if not.
            //When we check this, we are asserting that the point with lower x is out of the bigger skyline.
            //in case y == maximum, it means y coordinate of the skyline is under the maximum, so the point would be inside.
            result.push_back({ x, maxim });
            y = maxim;
        }
    }
    while (i < s1.size()) {
        result.push_back({ s1[i++] });
    }
    while (j < s2.size()) {
        result.push_back({ s2[j++] });
    }
    return result;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        Skyline s1 = read_skyline();
        Skyline s2 = read_skyline();
        Skyline ss = skyline_superposition(s1, s2);
        print_skyline(ss);
    }
}
