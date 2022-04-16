#include <iostream>
#include <vector>

using namespace std;

int merge(vector<int>& v, int left, int middle, int right) {
  vector<int> f(right - left + 1); //mida del vector
  int i = left, j = middle + 1, k = 0, inversions = 0;
  while (i <= middle and j <= right) { //esetem dins de les dues subdivisions
    if (v[i] <= v[j]) f[k++] = v[i++];
    else {
      f[k++] = v[j++];
      inversions += (middle + 1) - i;
    }
  }
  while (i <= middle) f[k++] = v[i++];
  while (j <= right) f[k++] = v[j++];
  for (int l = left; l <= right; ++l) v[l] = f[l - left];
  return inversions;
}

//accio que ens crea la part esquerra recursiva i la part dreta
int merge_sort(vector<int>& v, int left, int right) {
  if (left >= right) return 0; //indica que ja hem explorat totes les posicions del vector
  int middle = (left + right) / 2;
  return merge_sort(v, left, middle) + merge_sort(v, middle + 1, right) + merge(v, left, middle, right);
}

int inversions(vector<int>& v) {
  return merge_sort(v, 0, v.size() - 1);
}


int main() {
  int n;
  while (cin >> n) {
    vector<int> v(n);
    for (int& x : v) cin >> x;
    cout << inversions(v) << endl;
  }
}
