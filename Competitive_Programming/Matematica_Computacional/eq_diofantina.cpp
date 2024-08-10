#include <bits/stdc++.h>
using namespace std;

#define int long long

int gcdExtended(int a, int b, int &x, int &y) {

    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }

    int x1, y1;
    int res = gcdExtended(b % a, a, x1, y1);

    x = y1 - (b / a) * x1;
    y = x1;

    return res;
}

int32_t main() {
    int a, b, c; cin >> a >> b >> c;
    if ((c % gcd(a, b)) != 0) cout << "-1\n";
    else {
        int x, y;
        gcdExtended(a, b, x, y);
        cout << "1\n";
        int mult = c / gcd(a, b);
        x *= mult;
        y *= mult;
        cout << x << " " << y << "\n";
    }
}