#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        vector<string> a(n);
        vector<vector<string>> b(m, vector<string>(n));
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) cin >> b[i][j];
        }

        bool isPossible = 1;

        vector<int> cnt(m);

        for (int i = 0; i < n; i++) {
            bool ok = 0;
            for (int j = 0; j < m; j++) {
                if (a[i] == b[j][i]) {
                    ok = 1;
                    break;
                }
            }
            if (!ok) {
                isPossible = 0;
                break;
            }
        }

        
        if (!isPossible) {
            cout << "-1\n";
            continue;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i] == b[j][i]) {
                    cnt[j]++;
                }
            }

        }

        int best = 0;
        for (int i = 0; i < m; i++) best = max(best, cnt[i]);

        cout << n + (n - best) * 2 << "\n";
    }
}