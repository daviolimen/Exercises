/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: range
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

int n, dp[251][251];
char mat[251][251];

int main() {
    ifstream cin ("range.in");
    ofstream cout ("range.out");
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mat[i][j];
        }
    }

    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (mat[i][j] == '0') continue;
            dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            ans[dp[i][j]]++;
        }
    }

    for (int i = n - 1; i >= 2; i--) {
        ans[i] += ans[i + 1];
    }

    for (int i = 2; i <= n; i++) {
        if (!ans[i]) continue;
        cout << i << " " << ans[i] << "\n";
    }
    return 0;
}