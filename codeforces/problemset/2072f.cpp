#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000100;

int twoFac[MAXN], fact[MAXN];

void precomp(int n) {
    twoFac[0] = 0;
    for (int i = 1; i <= n; i++) twoFac[i] = (i % 2) ? 0 : 1 + twoFac[i / 2];
    fact[0] = 0;
    for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] + twoFac[i];
}

int main() {
    precomp(1000000);
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        for (int i = 0; i < n; i++) {
            int temp = fact[n - 1] - fact[i] - fact[n - 1 - i];
            if (temp) cout << 0;
            else cout << k;
            cout << " \n"[i == (n - 1)];
        }
    }
}