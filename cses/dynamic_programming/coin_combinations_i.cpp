#include <bits/stdc++.h>
using namespace std;

#define MAXN 100
#define MAXX 1000001

const int mod = 1e9 + 7;

int n, x, coins[MAXN], dp[MAXX];

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> coins[i];

    dp[0] = 1;

    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i - coins[j] >= 0) {
                dp[i] += dp[i - coins[j]];
                dp[i] %= mod;
            }
        }
    }
    cout << dp[x] << "\n";
}