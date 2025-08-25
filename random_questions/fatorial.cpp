#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;

int n, dp[MAXN], factdp[10];

int fact(int x) {
    if (x == 1) return 1;
    if (factdp[x] != 0) return factdp[x];
    return factdp[x] = x * fact(x - 1);
}

int main() {
    cin >> n;
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int x = 1; x <= 8; x++) {
            if (i - fact(x) < 0) continue;
            dp[i] = min(dp[i], dp[i - fact(x)] + 1);
        }
    }
    cout << dp[n] << "\n";
}