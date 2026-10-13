#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001

int n, arr[MAXN][3], dp[MAXN][3];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (j == k) continue;
                dp[i][j] = max(dp[i][j], dp[i - 1][k] + arr[i][j]);
            }
        }
    }

    cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << "\n";
}