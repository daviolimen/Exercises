#include <bits/stdc++.h>
using namespace std;

double check(double x) {
    return (x * x + sqrt(x));
}

int main() {
    double C; cin >> C;

    double l = 0, r = 1e5;

    for (int i = 0; i < 100; i++) {
        double m = (l + r) / 2;
        if (check(m) <= C) l = m;
        else r = m;
    }

    cout << setprecision(20) << l << "\n";
}