#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, m, k; cin >> n >> m >> k;
        vector<int> a(n);
        int cnt = n / (m + 1);
        cnt = max(cnt, k);
        for (int i = 0; i < n; i++) a[i] = i % cnt;
        for (int i = 0; i < n; i++) cout << a[i] << " \n"[i == (n - 1)];
    }
}