#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
  double x, y;
};

bool comp_x(const Point& p1, const Point& p2) {
  return p1.x < p2.x;
}

bool comp_y(const Point& p1, const Point& p2) {
  return p1.y < p2.y;
}

double distance(const Point& p1, const Point& p2) {
  return hypot(p1.x - p2.x, p1.y - p2.y); //el hypot ens serveix per calcular el modul
}

double closest_pair_distance(const vector<Point>& p, int left, int right) {
  //un cop ja hem ordenat el vector segons les coordenades x, dividim el vector recursivament
  if (right - left <= 2) { //nomes tenim tres punts o menys
    double minimal = INFINITY;
    for (int i = left; i <= right; ++i) {
      for (int j = i + 1; j <= right; ++j) {
        double d = distance(p[i], p[j]);
        if (d < minimal) minimal = d;
      }
    }
    return minimal;
  }

  int middle = (left + right) / 2;

  double distance_left = closest_pair_distance(p, left, middle);
  double distance_right = closest_pair_distance(p, middle + 1, right);

  double minimal = min(distance_left, distance_right);
  vector<Point> strip = {p[middle]};
  for (int i = middle - 1; i >= left and p[middle].x - p[i].x <= minimal; --i) strip.push_back(p[i]);
  for (int i = middle + 1; i <= right and p[i].x - p[middle].x <= minimal; ++i) strip.push_back(p[i]);
  sort(strip.begin(), strip.end(), comp_y);
  for (int i = 0; i < strip.size(); ++i) {
    for (int j = i + 1; j < strip.size(); ++j) {
      if (p[i].y - p[j].y > minimal) break;
      double d = distance(p[i], p[j]);
      if (d < minimal) minimal = d;
    }
  }
  return minimal;
}

int main() {
  cout.setf(ios::fixed);
  cout.precision(5);

  vector<Point> p;
  double x, y;
  while (cin >> x >> y) p.push_back({x, y});
  sort(p.begin(), p.end(), comp_x);
  cout << closest_pair_distance(p, 0, p.size() - 1) << endl;
}
