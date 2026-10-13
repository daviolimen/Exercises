/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: nuggets
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ifstream cin ("nuggets.in");
    ofstream cout ("nuggets.out");
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    sort(nums.begin(), nums.end());

    vector<int> dp(nums[0], 0x3f3f3f3f3f3f3f3f);
    dp[0] = 0;
    // for (int i = 1; i < nums[0]; i++) {
    //     for (int j = 1; j < n; j++) {
    //         for (int k = 1; k < 256; k++) {
    //             int curr = ((i + nums[0] - (((nums[j] % nums[0]) * (k % nums[0])) % nums[0])) % nums[0]);
    //             curr = ((curr + nums[0]) % nums[0]);
    //             dp[i] = min(dp[i], dp[curr] + nums[j] * k);
    //         }
    //     }
    // }

    for (int i = 1; i < 256; i++) {
        for (int j = 1; j < n; j++) {
            for (int k = 1; k < nums[0]; k++) {
                int curr = ((k + nums[0] - (((nums[j] % nums[0]) * (i % nums[0])) % nums[0])) % nums[0]);
                curr = (curr + nums[0]) % nums[0];
                dp[k] = min(dp[k], dp[curr] + i * nums[j]);
            }
        }
    }

    int mx = 0, greatestIdx = -1;
    for (int i = 0; i < nums[0]; i++) {
        if (dp[i] > mx) {
            mx = dp[i];
            greatestIdx = i;
        }
    }

    if (mx == 0x3f3f3f3f3f3f3f3f || mx == 0) cout << "0\n";
    else cout << mx - nums[0] << "\n";
    return 0;
}