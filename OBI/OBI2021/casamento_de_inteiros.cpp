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

    int da[10], db[10], ia = 0, ib = 0;

    memset(da, 0, sizeof(da));
    memset(db, 0, sizeof(db));

    while (a > 0) {
        da[ia++] = a % 10;
        a /= 10;
    }

    while (b > 0) {
        db[ib++] = b % 10;
        b /= 10;
    }

    bool foi1 = false, foi2 = false;
    int res1 = 0, res2 = 0, ctr1 = 0, ctr2 = 0;
    for (int i = 0; i < max(ia, ib); i++) {
        if (da[i] > db[i]) {
            res1 += da[i] * xpow(10, ctr1++);
            foi1 = true;
        } else if (db[i] > da[i]) {
            res2 += db[i] * xpow(10, ctr2++);
            foi2 = true;
        } else {
            res1 += da[i] * xpow(10, ctr1++);
            res2 += db[i] * xpow(10, ctr2++);
            foi1 = foi2 = true;
        }
    }
    if (!foi1) res1 = -1;
    if (!foi2) res2 = -1;

    if (res1 > res2) cout << res2 << " " << res1 << "\n";
    else cout << res1 << " " << res2 << "\n";
}