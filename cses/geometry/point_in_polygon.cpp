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
    C dir = (conj(p2 - p1) * (p - p1)).Y;
    if (dir > 0) return 1;
    if (dir < 0) return -1;
    return 0;
}

int main() {
    int n, m; cin >> n >> m;
    vector<P> poly(n);
    for (int i = 0; i < n; i++) read(poly[i]);

    for (int i = 0; i < m; i++) {
        P p; read(p);

        int cnt = 0;
        bool flag = 0;

        for (int j = 0; j < n; j++) {
            P p1 = poly[j], p2 = poly[((j + 1) % n)];
            C x1 = min(p1.X, p2.X), x2 = max(p1.X, p2.X);
            C y1 = min(p1.Y, p2.Y), y2 = max(p1.Y, p2.Y);

            if ((x1 <= p.X) && (p.X <= x2) && (y1 <= p.Y) && (p.Y <= y2) && (sense(p, p1, p2) == 0)) {
                flag = 1;
                break;
            }

            if ((p1.Y <= p.Y) && (p.Y < p2.Y) && (sense(p, p1, p2) > 0)) cnt++;
            if ((p2.Y <= p.Y) && (p.Y < p1.Y) && (sense(p, p2, p1) > 0)) cnt++;
        }

        if (flag) cout << "BOUNDARY\n";
        else {
            if (cnt & 1) {
                cout << "INSIDE\n";
            } else {
                cout << "OUTSIDE\n";
            }
        }
    }
}