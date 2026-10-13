#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001

int n, height[MAXN], dp[MAXN];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> height[i];

    dp[2] = abs(height[2] - height[1]);
    for (int i = 3; i <= n; i++) {
        dp[i] = min(dp[i - 1] + abs(height[i] - height[i - 1]), dp[i - 2] + abs(height[i] - height[i - 2]));
    }

    cout << dp[n] << "\n";
}