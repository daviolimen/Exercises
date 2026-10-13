#include <bits/stdc++.h>
using namespace std;

long long xpow(long long a, long long b, long long m) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
        a %= m;
        res %= m;
    }
    return res;
}

int main() {
    long long a, p; cin >> a >> p;
    if (gcd(a, p) != 1) cout << "-1\n";
    else cout << xpow(a, p - 2, p) << "\n";
}