#include <bits/stdc++.h>
using namespace std;

const int MAXN = 501;

int precomp[MAXN];

int main() {
    for (int i = 2; i <= 500; i++) precomp[i] = i * (i - 1) / 2;
    int tt; cin >> tt;
    while (tt--) {
        int k; cin >> k;
        vector<pair<int, int>> ans;
        int currX = 0, currY = 0;
        while (k > 0) {
            int idx = upper_bound(precomp, precomp + MAXN, k) - precomp;
            idx--;
            k -= precomp[idx];
            for (int i = 0; i < idx; i++) {
                ans.emplace_back(currX, currY);
                currX++;
            }
            currX++;
            currY++;
        }
        cout << ans.size() << "\n";
        for (auto P : ans) {
            cout << P.first << " " << P.second << "\n";
        }
    }
}