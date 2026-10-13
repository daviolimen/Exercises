#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20, MAXM = 1 << 20;

int n, x, w[MAXN];
pair<int, int> dp[MAXM];

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> w[i];

    dp[0] = {1, 0};

    for (int s = 1; s < (1 << n); s++) {
        dp[s] = {n + 1, 0};

        for (int i = 0; i < n; i++) {
            if (s & (1 << i)) {
                auto option = dp[s ^ (1 << i)];

                if (option.second + w[i] <= x) {
                    option.second += w[i];
                } else {
                    option.first++;
                    option.second = w[i];
                }
                dp[s] = min(dp[s], option);
            }
        }
    }

    cout << dp[(1 << n) - 1].first << "\n";
}