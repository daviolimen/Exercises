/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: buylow
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

int main() {
    // ifstream cin ("buylow.in");
    // ofstream cout ("buylow.out");
    int n; cin >> n;
    vector<int> arr(n + 1);
    vector<pair<int, int>> dp(n + 1, {1, 1});
    for (int i = 1; i <= n; i++) cin >> arr[i];

    for (int i = 2; i <= n; i++) {
        for (int j = i - 1; j > 0; j--) {
            if (arr[j] <= arr[i]) continue;
            if (dp[j].first + 1 < dp[i].first) continue;
            if (dp[j].first + 1 == dp[i].first) {
                dp[i].second += dp[j].second;
            } else {
                dp[i].first = dp[j].first + 1;
                dp[i].second = dp[j].second;
            }
        }

        for (int j = i - 1; j > 0; j--) {
            if (arr[i] != arr[j]) continue;
            if (dp[i].first != dp[j].first) continue;
            dp[i].second -= dp[j].second;
        }
    }

    int bestLength = 0, numOfSeq = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[i].first > bestLength) {
            bestLength = dp[i].first;
            numOfSeq = dp[i].second;
        } else if (dp[i].first == bestLength) {
            numOfSeq += dp[i].second;
        }
    }

    cout << bestLength << " " << numOfSeq << "\n";
    return 0;
}