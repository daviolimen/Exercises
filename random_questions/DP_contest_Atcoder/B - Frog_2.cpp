#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define MAXN 100001

int n, k, height[MAXN], dp[MAXN];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> height[i];

    memset(dp, INF, sizeof(dp));
    dp[0] = dp[1] = 0;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if ((i - j) > 0) {
                dp[i] = min(dp[i], dp[i - j] + abs(height[i] - height[i - j]));
            }
        }
    }

    cout << dp[n] << "\n";
}