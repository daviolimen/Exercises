#include <bits/stdc++.h>
using namespace std;

typedef long long C;
typedef complex<C> P;
#define X real()
#define Y imag()

void read(P &p) {
    C x, y; cin >> x >> y;
    p = {x, y};
}

int sense(P p, P p1, P p2) {
    C dir = ((conj(p2 - p1)) * (p - p1)).Y;
    if (dir > 0) return 1;
    if (dir < 0) return -1;
    return 0;
}

bool quick_check(P p1, P p2, P p3, P p4) {
    int x1, x2, x3, x4, y1, y2, y3, y4;
    x1 = min(p1.X, p2.X), x2 = max(p1.X, p2.X);
    y1 = min(p1.Y, p2.Y), y2 = max(p1.Y, p2.Y);
    x3 = min(p3.X, p4.X), x4 = max(p3.X, p4.X);
    y3 = min(p3.Y, p4.Y), y4 = max(p3.Y, p4.Y);
    return ((x1 > x4) || (x3 > x2) || (y1 > y4) || (y3 > y2));
}

bool check(P p1, P p2, P p3, P p4) {
    if ((sense(p1, p2, p3) * sense(p1, p2, p4)) > 0) return false;
    if ((sense(p3, p4, p1) * sense(p3, p4, p2)) > 0) return false;
    return true;
}

int main() {
    int tt; cin >> tt;
    while (tt--) {
        P p1, p2, p3, p4; read(p1); read(p2); read(p3); read(p4);
        if (quick_check(p1, p2, p3, p4)) {
            cout << "NO\n";
        } else {
            if (check(p1, p2, p3, p4)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}