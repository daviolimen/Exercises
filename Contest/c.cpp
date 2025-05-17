#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(1), cpy(1);

        int cnt = 0;

        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            if (x == a[cnt]) continue;
            a.push_back(x);
            cpy.push_back(x);
            cnt++;
        }

        sort(cpy.begin() + 1, cpy.end());
        n = a.size() - 1;

        int ctr = 0;
        map<int, int> comp;
        for (int i = 1; i <= n; i++) {
            if (comp.find(cpy[i]) == comp.end()) {
                comp[cpy[i]] = ctr++;
            }
        }

        vector<vector<int>> pos(n, vector<int>());
        for (int i = 1; i <= n; i++) {
            a[i] = comp[a[i]];
            pos[a[i]].push_back(i);
        }

        vector<bool> pressed(n + 2);
        ctr--;

        int ans = 0;
        for (int i = ctr; i >= 0; i--) {
            for (auto x : pos[i]) {
                pressed[x] = 1;
                if (pressed[x + 1] || pressed[x - 1]) continue;
                ans++;
            }
        }

        cout << ans << "\n";
    }
}