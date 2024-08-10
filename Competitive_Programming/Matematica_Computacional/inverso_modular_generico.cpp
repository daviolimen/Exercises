#include <bits/stdc++.h>
using namespace std;

int gcdExtended(int a, int b, int &x, int &y) {

    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }

    int x1, y1;
    int ret = gcdExtended(b % a, a, x1, y1);

    x = y1 - (b / a) * x1;
    y = x1;
    return ret;
}

int main() {
    int a, m; cin >> a >> m;
    if (gcd(a, m) != 1) { // nao tem como
        cout << "-1\n";
        return 0;
    }
    // o inverso de a modulo m sera o x na equacao: ax + my = gcd(a, m)
    int x, y;
    gcdExtended(a, m, x, y);
    cout << x << "\n";
}