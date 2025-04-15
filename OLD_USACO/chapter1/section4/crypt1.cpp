/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: crypt1
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

vector<int> findDigs(int x) {
    vector<int> res;
    while (x > 0) {
        res.push_back(x % 10);
        x /= 10;
    }
    return res;
}

int main() {
    ifstream cin ("crypt1.in");
    ofstream cout ("crypt1.out");

    int n; cin >> n;
    unordered_set<int> nums;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        nums.insert(x);
    }

    int ans = 0;
    // vector<pair<int, int>> sols;

    for (int i = 100; i <= 999; i++) {
        auto v1 = findDigs(i);
        bool bad = 0;
        for (auto x : v1) {
            if (nums.find(x) == nums.end()) {
                bad = 1;
                break;
            }
        }
        if (bad) continue;

        for (int j = 10; j <= 99; j++) {
            bool bad2 = 0;
            auto v2 = findDigs(j);
            for (auto x : v2) {
                if (nums.find(x) == nums.end()) {
                    bad2 = 1;
                    break;
                }
            }
            if (bad2) continue;

            if (i * v2[0] >= 1000) continue;
            if (i * v2[1] >= 1000) continue;
            if (i * j >= 10000) continue;

            auto v3 = findDigs(i * v2[0]);
            auto v4 = findDigs(i * v2[1]);
            auto v5 = findDigs(i * j);
            
            for (auto x : v3) {
                if (nums.find(x) == nums.end()) {
                    bad2 = 1;
                    break;
                }
            }

            if (bad2) continue;

            for (auto x : v4) {
                if (nums.find(x) == nums.end()) {
                    bad2 = 1;
                    break;
                }
            }

            if (bad2) continue;

            for (auto x : v5) {
                if (nums.find(x) == nums.end()) {
                    bad2 = 1;
                    break;
                }
            }

            if (bad2) continue;

            ans++;
            // sols.emplace_back(i, j);
        }
    }

    cout << ans << "\n";
    // for (auto P : sols) cout << P.first << " " << P.second << "\n";

    return 0;
}