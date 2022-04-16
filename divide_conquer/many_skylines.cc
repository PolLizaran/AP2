#include <iostream>
#include <vector>

using namespace std;

// Structure to represent a point in a 2D space
struct Point {
    int x, y;
};

// A skyline is a vector of Points sorted by the x coordinate
using Skyline = vector<Point>;

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

//Them main idea of this function is to divide the skylines in two parts to gain running speed. We call recursively the function
//one time to create the left part of the skylines and then the right.
Skyline skyline_recursion(const vector<Skyline>& skylines, int left, int right)
{
    //base cases;
    if (right - left == 0) { // no Skylines remaining
        return Skyline {};
    }
    if (right - left == 1) { //just one Skyline remains
        return skylines[left];
    }

    int mid = (left + right) / 2;
    //we create two additional vectors of points containing the skylines points distinguissing between the left ones and the right ones
    Skyline left_skylines = skyline_recursion(skylines, left, mid);
    //it is very important not to use skilines.front() ej. as this returns the element of the end or the front and not an integer to make the recursion with
    Skyline right_skylines = skyline_recursion(skylines, mid, right);
    return skyline_superposition(left_skylines, right_skylines);
}

Skyline skyline(const vector<Skyline>& skylines)
{
    return skyline_recursion(skylines, 0, skylines.size());
}

int main()
{
    int s;
    cin >> s;
    vector<Skyline> skylines(s);
    for (Skyline& sl : skylines) {
        sl = read_skyline();
    }
    print_skyline(skyline(skylines));
}
