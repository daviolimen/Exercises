#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m));
        vector<vector<int>> dp(n, vector<int>(m));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
                dp[i][j] = (mat[i][j] == '*');
                if (j > 0) dp[i][j] += dp[i][j - 1];
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < n - i; k++) {
                    if ((k > j) || (k >= m - j)) break;
                    int left = (j - k - 1 < 0) ? 0 : dp[i + k][j - k - 1];
                    if (dp[i + k][j + k] - left >= 2 * k + 1) ans++;
                    else break;
                }
            }
        }

        cout << ans << "\n";
    }
}