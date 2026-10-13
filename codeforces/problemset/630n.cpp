#include <bits/stdc++.h>
using namespace std;

int main() {
    long double a, b, c; cin >> a >> b >> c;
    long double delta = sqrt(b * b - 4.0 * a * c);
    long double x1 = (-b + delta) / (2.0 * a);
    long double x2 = (-b - delta) / (2.0 * a);
    cout << fixed << setprecision(15) << max(x1, x2) << "\n" << min(x1, x2) << "\n";
}