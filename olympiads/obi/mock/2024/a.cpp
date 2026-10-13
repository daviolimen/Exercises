#include <bits/stdc++.h>
using namespace std;

const int MAXN = 301;

int N, K, T, arr[MAXN], pos[MAXN], dp[MAXN][MAXN][MAXN * 9];

int main() {
    cin >> N >> K >> T;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    int cnt = 1;
    for (int i = 1; i <= N; i++) {
        int x; cin >> x;
        if (!x) continue;
        pos[cnt++] = i;
    }

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= min(i, K); j++) {
            for (int k = 1; k <= 9 * j; k++) dp[i][j][k] = 0x3f3f3f3f;
        }
    }

    int ans = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= min(i, K); j++) {
            for (int k = 1; k <= 9 * j; k++) {
                if ((i - 1 >= j) && (k <= 9 * j)) dp[i][j][k] = dp[i - 1][j][k];
                if (k - arr[i] < 0) continue;
                if (k - arr[i] <= 9 * (j - 1)) dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - 1][k - arr[i]] + abs(i - pos[j]));
                if (dp[i][j][k] <= T) ans = max(ans, k);
            }
        }
    }

    cout << ans << "\n";
}