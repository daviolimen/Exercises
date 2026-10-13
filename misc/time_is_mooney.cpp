#include <bits/stdc++.h>
using namespace std;

int n, m, c, money[1001], dp[1001][1001];
vector<int> radj[1001];

int main() {
    ifstream cin("time.in");
    ofstream cout("time.out");
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++) cin >> money[i];
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        radj[b].push_back(a);
    }

    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            dp[i][j] = INT_MIN;
        }
    }

    dp[0][1] = 0;

    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= n; j++) {
            for (auto x : radj[j]) dp[i][j] = max(dp[i - 1][x] + money[j], dp[i][j]);
        }
    }

    int ans = 0;
    for (int i = 1; i <= 1000; i++) {
        if (dp[i][1] < 0) continue;
        ans = max(ans, dp[i][1] - c * i * i);
    }

    cout << ans << "\n";
}