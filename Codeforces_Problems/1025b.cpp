#include <bits/stdc++.h>
using namespace std;

long long findFactor(long long x) {
    for (long long i = 2; i * i <= x; i++) {
        if (x % i == 0) return i;
    }
    return x;
}

int main() {
    int n; cin >> n;
    long long a, b; cin >> a >> b;
    long long g = lcm(a, b);
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        g = gcd(g, lcm(a, b));
    }

    if (g == 1) cout << "-1\n";
    else {
        int g1 = gcd(g, a), g2 = gcd(g, b);
        if (g1 == 1) cout << findFactor(g2) << "\n";
        else cout << findFactor(g1) << "\n";
    }
}