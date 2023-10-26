#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;

    Point(int _x = 0, int _y = 0) {
        x = _x;
        y = _y;
    }

    Point operator+(const Point& a) {
        return Point(x + a.x, y + a.y);
    }

    Point operator-(const Point& a) {
        return Point(x - a.x, y - a.y);
    }

    int operator*(const Point& a) {
        return ((x * a.x) + (y * a.y));
    }

    int operator/(const Point& a) {
        return ((x * a.y) - (y * a.x));
    }
};

int sq(int x) {return x * x;}

int dist(Point const& a, Point const& b) {
    return sq(a.x - b.x) + sq(a.y - b.y);
}

int sign(int x) {
    return (x > 0) ? 1 : -1;
}

Point a[8];

bool check() {
    if (dist(a[1], a[2]) + dist(a[1], a[3]) <= dist(a[2], a[3])) return false;
    if (dist(a[1], a[2]) != dist(a[1], a[3])) return false;
    if (((a[3] - a[2]) / (a[4] - a[2]) != 0) || ((a[3] - a[2]) / (a[5] - a[2]) != 0)) return false;
    if (((a[2] + a[3]).x != (a[4] + a[5]).x) || ((a[2] + a[3]).y != (a[4] + a[5]).y)) return false;
    if (dist(a[2], a[3]) <= dist(a[4], a[5])) return false;
    if ((dist(a[2], a[4]) + dist(a[4], a[6]) != dist(a[2], a[6])) || (dist(a[3], a[5]) + dist(a[5], a[7]) != dist(a[3], a[7]))) return false;
    if (dist(a[4], a[6]) != dist(a[5], a[7])) return false;
    if (sign((a[2] - a[1]) / (a[2] - a[3])) == sign((a[2] - a[6]) / (a[2] - a[3]))) return false;
    return true;
}

int main() {
    for (int i = 1; i <= 7; i++) cin >> a[i].x >> a[i].y;

    cout << ((check()) ? "S\n" : "N\n");
}