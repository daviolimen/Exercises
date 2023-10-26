#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
    Point() {
        x = 0;
        y = 0;
    }
    Point(int _x, int _y) {
        x = _x;
        y = _y;
    }
};

bool covered(Point a, Point b, Point c) {
    if ((b.x <= a.x) && (a.x <= c.x) && (b.y <= a.y) && (a.y <= c.y)) return true;
    return false;
}

int main() {
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    int x1, y1, x2, y2;
    Point a, b, c, d;
    cin >> x1 >> y1 >> x2 >> y2;
    a.x = x1, b.x = x2, a.y = y1, b.y = y2;
    cin >> x1 >> y1 >> x2 >> y2;
    c.x = x1, d.x = x2, c.y = y1, d.y = y2;

    bool covers[] = {false, false, false, false};
    if (covered(a, c, d)) covers[0] = true;
    if (covered(Point(a.x, b.y), c, d)) covers[1] = true;
    if (covered(b, c, d)) covers[2] = true;
    if (covered(Point(b.x, a.y), c, d)) covers[3] = true;

    int area = ((b.x - a.x) * (b.y - a.y));
    if (covers[0] && covers[1] && covers[2] && covers[3]) {
        cout << "0\n";
    } else if (covers[0] && (covers[1])) {
        cout << ((b.x - d.x) * (b.y - a.y)) << "\n";
    } else if (covers[1] && covers[2]) {
        cout << ((b.x - a.x) * (c.y - a.y)) << "\n";
    } else if (covers[2] && (covers[3])) {
        cout << ((c.x - a.x) * (b.y - a.y)) << "\n";
    } else if (covers[3] && covers[0]) {
        cout << ((b.x - a.x) * (b.y - d.y)) << "\n";
    } else {
        cout << area << "\n";
    }
    return 0;
}