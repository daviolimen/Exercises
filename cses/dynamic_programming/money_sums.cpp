#include <bits/stdc++.h>
using namespace std;

#define MAXN 101
#define MAXSUM 100001

int n, coins[MAXN];
bool dp[MAXN][MAXSUM];

int main() {
    cin >> n;
    int maxSum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> coins[i];
        maxSum += coins[i];
    }
    sort(coins + 1, coins + n + 1);

    for (int i = 0; i <= n; i++) dp[i][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= maxSum; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - coins[i] >= 0) dp[i][j] = dp[i][j] || dp[i - 1][j - coins[i]];
        }
    }

    vector<int> ans;
    for (int i = 1; i <= maxSum; i++) {
        if (dp[n][i]) ans.push_back(i);
    }

    cout << ans.size() << "\n";
    for (auto x : ans) cout << x << " ";
    cout << "\n";
}