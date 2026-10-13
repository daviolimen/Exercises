#include <bits/stdc++.h>
using namespace std;

int main() {
    int tt; cin >> tt;
    while (tt--) {
        int n, k, p; cin >> n >> k >> p;
        if (n * p < abs(k)) {
            cout << "-1\n";
        } else {
            cout << ((abs(k) + p - 1) / p) << "\n";
        }
    }
}