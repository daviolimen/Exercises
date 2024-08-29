#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> dp(n + 1, 0x3f3f3f3f);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int num = i;
        while (num > 0) {
            int dig = num % 10;
            num /= 10;
            if (i - dig < 0) continue;
            dp[i] = min(dp[i], dp[i - dig] + 1);
        }
    }
    cout << dp[n] << "\n";
}