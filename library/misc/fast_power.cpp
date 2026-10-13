#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll fastPower(ll b, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res *= b;
        n >>= 1;
        b *= b;
    }
    return res;
}

int main() {
    ll x, y; cin >> x >> y;
    cout << fastPower(x, y) << "\n";
}