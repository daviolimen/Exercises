/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: stamps
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 51, MAXNUM = 2000100;

int k, n, vals[MAXN], dp[MAXNUM];

int main() {
    ifstream cin ("stamps.in");
    ofstream cout ("stamps.out");
    cin >> k >> n;
    for (int i = 0; i < n; i++) cin >> vals[i];
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    dp[0] = 0;

    int ans = -1;

    for (int i = 1; i < MAXNUM; i++) {
        for (int j = 0; j < n; j++) {
            if (i - vals[j] < 0) continue;
            dp[i] = min(dp[i], dp[i - vals[j]] + 1);
        }
        if ((dp[i] == 0x3f3f3f3f) || (dp[i] > k)) {
            ans = i - 1;
            break;
        }
    }

    cout << ans << "\n";
    return 0;
}