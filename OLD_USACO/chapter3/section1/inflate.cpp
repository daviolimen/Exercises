/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: inflate
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

int n, m, dp[10001];

int main() {
    ifstream cin ("inflate.in");
    ofstream cout ("inflate.out");
    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        int p, t; cin >> p >> t;
        for (int j = 1; j <= m; j++) {
            if (j - t < 0) continue;
            dp[j] = max(dp[j], dp[j - t] + p);
        }
    }

    cout << dp[m] << "\n";
    return 0;
}