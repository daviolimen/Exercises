#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        bool ok = 0;
        long double l, c, r1, r2; cin >> l >> c >> r1 >> r2;
        if (l < 1e-6) break;
        if (r1 > r2) swap(r1, r2);
        if (l > c) swap(l, c);
        long double soma = r1 + r2;
        for (long double ang = 0; ang < M_PI * 0.5; ang += 0.001) {
            long double t1 = soma * (1 + sin(ang));
            long double t2 = soma * (1 + cos(ang));
            if (t1 > t2) swap(t1, t2);
            t1 = max(t1, 2 * r2);
            t2 = max(t2, 2 * r2);
            if ((t1 <= l + 0.01) && (t2 <= c + 0.01)) {
                ok = 1;
                break;
            }
        }

        if (ok) cout << "S\n";
        else cout << "N\n";
    }
}