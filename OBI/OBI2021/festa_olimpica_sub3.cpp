#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

ull n, m;

int main() {
    cin >> n >> m;
    ull mod = 1;
    for (int i = 0; i < m; i++) {
        int a; cin >> a; mod *= a;
    }

    for (ull i = 1; i <= n; i++) {
        if (i % mod == 1) cout << i << "\n";
    }
}