/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: numtri
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream cin ("numtri.in");
    ofstream cout ("numtri.out");
    int r; cin >> r;
    vector<vector<int>> tri(r, vector<int>(r)), dp(r, vector<int>(r));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> tri[i][j];
        }
    }

    dp[0][0] = tri[0][0];

    for (int i = 1; i < r; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] = max(dp[i - 1][j], (j - 1 < 0) ? 0 : dp[i - 1][j - 1]) + tri[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < r; i++) ans = max(ans, dp[r - 1][i]);
    cout << ans << "\n";
    return 0;
}