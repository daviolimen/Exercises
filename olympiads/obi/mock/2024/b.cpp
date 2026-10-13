#include <bits/stdc++.h>
using namespace std;

int n, arr[101], dp[101][101];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    memset(dp, 0x3f3f3f3f, sizeof(dp));
    for (int i = 1; i <= n; i++) dp[i][i] = 0;

    for (int sz = 2; sz <= n; sz++) {
        for (int i = 1; i <= n - sz + 1; i++) {
            int intEnd = i + sz - 1, mx1 = 0;
            vector<int> mx2(101);
            for (int j = intEnd; j >= i; j--) mx2[j] = max(mx2[j + 1], arr[j]);
            for (int j = i; j < intEnd; j++) {
                mx1 = max(mx1, arr[j]);
                dp[i][intEnd] = min(dp[i][intEnd], dp[i][j] + dp[j + 1][intEnd] + abs(mx1 - mx2[j + 1]));
            }
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << dp[i][j] << " \n"[j == n];
    //     }
    // }

    cout << dp[1][n] << "\n";
}