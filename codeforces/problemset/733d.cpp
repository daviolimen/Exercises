#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXX = (int) 1e9 + 10;

int32_t main() {
    int n; cin >> n;
    vector<vector<int>> stones(n, vector<int>(3));
    set<vector<int>> st;
    for (int i = 0; i < n; i++) {
        cin >> stones[i][0] >> stones[i][1] >> stones[i][2];
        sort(stones[i].begin(), stones[i].end(), greater<int>());
        stones[i].push_back(i);
        st.insert(stones[i]);
    }

    int mx = 0, ans[2] = {-1, -1};

    for (int i = 0; i < n; i++) {
        if (stones[i][2] > mx) {
            mx = stones[i][2];
            ans[0] = i;
            ans[1] = -1;
        }
        auto it = st.upper_bound(vector<int>({stones[i][0], stones[i][1], MAXX, -1}));
        it--;
        if ((*it)[3] == i) {
            if (it == st.begin()) continue;
            it--;
            if ((*it)[0] != stones[i][0]) continue;
            if ((*it)[1] != stones[i][1]) continue;
        }
        int diam = min({stones[i][0], stones[i][1], stones[i][2] + (*it)[2]});
        if (diam > mx) {
            mx = diam;
            ans[0] = i;
            ans[1] = (*it)[3];
        }
    }

    if (ans[1] == -1) {
        cout << "1\n" << ans[0] + 1 << "\n";
    } else {
        cout << "2\n" << ans[0] + 1 << " " << ans[1] + 1 << "\n";
    }
}