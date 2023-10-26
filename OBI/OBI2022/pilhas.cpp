#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f, MAXN = 501;

int n, k, arr[MAXN], prefix[MAXN], dp[MAXN][MAXN];

int ops(int l, int r) {
    return (((r - l + 1) * arr[r]) - (prefix[r] - prefix[l - 1]));
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    sort(arr + 1, arr + n + 1);

    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    memset(dp, INF, sizeof(dp));

    for (int i = 0; i < MAXN; i++) dp[0][i] = 0;

    for (int pos = 1; pos <= n; pos++) {
        for (int nval = 1; nval <= k; nval++) {
            for (int i = 1; i <= pos; i++) {
                dp[pos][nval] = min(dp[pos][nval], dp[pos - i][nval - 1] + ops(pos - i + 1, pos));
            }
        }
    }

    cout << dp[n][k] << "\n";
}