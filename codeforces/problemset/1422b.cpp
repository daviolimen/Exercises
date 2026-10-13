#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int mx = max({mat[i][j], mat[n - i - 1][j], mat[i][m - j - 1]});
                int mn = min({mat[i][j], mat[n - i - 1][j], mat[i][m - j - 1]});
                int soma = mat[i][j] + mat[n - i - 1][j] + mat[i][m - j - 1];
                ans += mx - mn;
                mat[i][j] = mat[n - i - 1][j] = mat[i][m - j - 1] = soma - mx - mn;
            }
        }

        cout << ans << "\n";
    }
}