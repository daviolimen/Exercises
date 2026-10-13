#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    int n, a; cin >> n >> a;
    vector<int> d(n);
    int soma = 0;
    for (auto &x : d) {
        cin >> x;
        soma += x;
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = max(d[i] - (a - n + 1), 0ll) + max((a - soma + d[i]) - 1, 0ll);
    }

    for (auto x : ans) cout << x << " ";
    cout << "\n";
}