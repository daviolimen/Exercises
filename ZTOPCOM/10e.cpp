#include <bits/stdc++.h>
using namespace std;

int main() {
    double r;
    while (cin >> r) {
        double ans = 2 * (M_PI - 2) * r * r;
        cout << fixed << setprecision(3) << ans << "\n";
    }
}