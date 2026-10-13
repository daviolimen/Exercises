#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        vector<int> a(n), b(n);
        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;
        int soma = -1;
        for (int i = 0; i < n; i++) {
            if (b[i] != -1) {
                soma = a[i] + b[i];
                break;
            }
        }
        if (soma != -1) {
            bool ok = true;
            for (int i = 0; i < n; i++) {
                if (b[i] == -1) {
                    b[i] = soma - a[i];
                    if ((b[i] > k) || (b[i] < 0)) {
                        ok = false;
                        break;
                    }
                } else {
                    if (a[i] + b[i] != soma) {
                        ok = false;
                        break;
                    }
                }
            }
            if (!ok) {
                cout << "0\n";
            } else {
                cout << "1\n";
            }
        } else {
            int mn = INT_MAX, mx = -1;
            for (int i = 0; i < n; i++) {
                mn = min(mn, a[i]);
                mx = max(mx, a[i]);
            }
            int somaMax = k + mn;
            int somaMin = mx;
            int ans = somaMax - somaMin + 1;
            if (ans <= 0) cout << "0\n";
            else cout << ans << "\n";
        }
    }
}