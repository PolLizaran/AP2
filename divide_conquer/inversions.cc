#include <algorithm> //to sort the two vectors
#include <iostream>
#include <vector>

using namespace std;

void read_vector()
{
    int n;
    cin >> n;
    vector<int>& v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
}

int inv_rec(vector<int>& v, int left, int right)
{
    if
}

//function that given a vector returns the number of inversions it has. We want a complexity of O(nlogn)
int inversions(const vector<int>& v)
{
    //idea: sort the left part of the vector and the right part to be able to compare both parts
    int n = v.size();

    //left part
    vector<int> left = inversions()

    //right part
}

int main()
{
    vector<int> v = read_vector(v);
}
