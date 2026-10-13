#include <bits/stdc++.h>
using namespace std;

const int MAXN = 402;

int n, k, arr[MAXN], dp[MAXN][MAXN];

int main() {
    ifstream cin("snakes.in");
    ofstream cout("snakes.out");
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    memset(dp, 0x3f3f3f3f, sizeof(dp));
    memset(dp[0], 0, sizeof(dp[0]));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k + 1; j++) {
            int soma = 0, mx = 0;
            for (int l = i; l > 0; l--) {
                soma += arr[l];
                mx = max(mx, arr[l]);
                dp[i][j] = min(dp[i][j], mx * (i - l + 1) - soma + dp[l - 1][j - 1]);
            }
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= k + 1; j++) {
    //         cout << dp[i][j] << " \n"[j == (k + 1)];
    //     }
    // }

    cout << dp[n][k + 1] << "\n";
}