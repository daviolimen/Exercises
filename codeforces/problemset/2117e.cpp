#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n), b(n), pos(n + 1, -1);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            pos[a[i]] = max(pos[a[i]], i);
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            pos[b[i]] = max(pos[b[i]], i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) ans = max(ans, i + 1);
            else {
                if (i < n - 1) {
                    if (a[i + 1] == a[i]) ans = max(ans, i + 1);
                    if (b[i + 1] == b[i]) ans = max(ans, i + 1);
                }
                if (pos[a[i]] > i + 1) ans = max(ans, i + 1);
                if (pos[b[i]] > i + 1) ans = max(ans, i + 1);
            }
        }

        cout << ans << "\n";
    }
}