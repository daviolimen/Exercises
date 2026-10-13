#include <bits/stdc++.h>
using namespace std;

#define MAXN 101

int n, arr[MAXN], dp[MAXN][MAXN][2];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        dp[i][i][0] = 0;
        cin >> dp[i][i][1];
    }

    for (int sz = 2; sz <= n; sz++) {
        for (int i = 1; i <= n - sz + 1; i++) {
            int fim = i + sz - 1;
            dp[i][fim][0] = 0x3f3f3f3f;
            for (int k = i; k <= i + sz - 2; k++) {
                int mx = max(dp[i][k][1], dp[k + 1][fim][1]);
                int num = (2 * mx - dp[i][k][1] - dp[k + 1][fim][1]) + dp[i][k][0] + dp[k + 1][fim][0]; 
                if (num < dp[i][fim][0]) {
                    dp[i][fim][0] = num;
                    dp[i][fim][1] = mx;
                }
            }
        }
    }

    cout << dp[1][n][0] << "\n";
}