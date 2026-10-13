#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, m, k; cin >> n >> m >> k;
        vector<int> pos;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int num = min({k, i + 1, n - k + 1, n - i}) * min({k, j + 1, m - k + 1, m - j});
                pos.push_back(num);
            }
        }

        sort(pos.begin(), pos.end(), greater<int>());
        
        int w; cin >> w;
        vector<int> vals(w);
        for (auto &x : vals) cin >> x;
        sort(vals.begin(), vals.end(), greater<int>());

        long long ans = 0;
        for (int i = 0; i < w; i++) ans += 1LL * vals[i] * pos[i];
        cout << ans << "\n";
    }
}