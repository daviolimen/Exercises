#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x) {
    if (x == 1) return 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int x, k; cin >> x >> k;
        if (k == 1) cout << ((isPrime(x) ? "YES\n" : "NO\n"));
        else {
            if (x == 1) {
                if (k == 2) cout << "YES\n";
                else cout << "NO\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}