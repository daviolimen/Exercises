#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, x, y;

ll solve() {
    ll res = 0, sizeX = n / x, sizeY = n / y, sizeXY = n / (lcm(x, y));
    sizeX -= sizeXY;
    sizeY -= sizeXY;
    res += ((sizeX * (n + n - sizeX + 1)) / 2);
    res -= ((sizeY * (1 + sizeY)) / 2);
    return res;
}

int main() {
    int tt; cin >> tt;
    while (tt--) {
        cin >> n >> x >> y;
        cout << solve() << "\n";
    }
}