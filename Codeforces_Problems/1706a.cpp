#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            a[i] = min(x, m - x + 1);
            
        }
        string ans(m, 'B');
        for (int i = 0; i < n; i++) {
            if (ans[a[i] - 1] == 'A') ans[m - a[i]] = 'A';
            else ans[a[i] - 1] = 'A';
        }
        cout << ans << "\n";
    }
}