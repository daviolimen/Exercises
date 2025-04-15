/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: ariprog
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

bool cmpY(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int n, m;
bitset<130000> bisq;

int main() {
    ifstream cin ("ariprog.in");
    ofstream cout ("ariprog.out");
    cin >> n >> m;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            bisq[i * i + j * j] = 1;
        }
    }

    vector<int> nums;
    for (int i = 0; i <= 2 * m * m; i++) if (bisq[i]) nums.push_back(i);

    int mx = 2 * m * m;
    vector<pair<int, int>> ans;

    for (auto a : nums) {
        for (int b = 1; b <= (mx - a) / (n - 1); b++) {
            bool ok = 1;
            for (int i = 0; i < n; i++) {
                if (!bisq[a + i * b]) {
                    ok = 0;
                    break;
                }
            }
            if (!ok) continue;
            ans.emplace_back(a, b);
        }
    }

    sort(ans.begin(), ans.end(), cmpY);

    if (ans.empty()) cout << "NONE\n";
    else for (auto P : ans) cout << P.first << " " << P.second << "\n";

    return 0;
}