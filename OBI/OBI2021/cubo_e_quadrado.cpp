#include <bits/stdc++.h>
using namespace std;

int xpow(int x, int p) {
    int res = 1;
    while (p > 0) {
        if (p & 1) res *= x;
        p >>= 1;
        x *= x;
    }
    return res;
}

int main() {
    int a, b;
    cin >> a >> b;
    int ctr = 0;
    for (int i = 1; i <= 22; i++) {
        int curr = xpow(i, 6);
        if ((a <= curr) && (b >= curr)) {
            ctr++;
        }
    }
    cout << ctr << "\n";
}