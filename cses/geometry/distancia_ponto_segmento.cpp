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
    C op1 = (conj(b - a) * (p - b)).real();
    C op2 = (conj(b - a) * (p - a)).real();
    if ((op1 > 0) && (op2 > 0)) cout << setprecision(10) << fixed << abs(p - b) << "\n";
    else if ((op1 < 0) && (op2 < 0)) cout << setprecision(10) << fixed << abs(p - a) << "\n";
    else {
        C dist = abs((conj(p - a) * (p - b)).imag());
        dist /= abs(b - a);
        cout << setprecision(10) << fixed << dist << "\n";
    }
}