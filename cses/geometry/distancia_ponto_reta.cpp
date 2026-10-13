#include <bits/stdc++.h>
using namespace std;

typedef long double C;
typedef complex<C> P;

void read(P &p) {
    C x, y; cin >> x >> y;
    p = {x, y};
}

int main() {
    P a, b, p; read(a); read(b); read(p);
    C area = (conj(p - a) * (p - b)).imag();
    C dist = abs(area) / (abs(b - a));
    cout << setprecision(10) << fixed << dist << "\n";
}