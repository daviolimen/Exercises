#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, q; cin >> n >> q;
        vector<int> p(n + 1), pos(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
            pos[p[i]] = i;
        }

        while (q--) {
            int l, r, k; cin >> l >> r >> k;
            if ((pos[k] < l) || (pos[k] > r)) {
                cout << "-1 ";
                continue;
            }
            int b = 0, f = 0, bb = 0, ff = 0;
            int i = l, j = r;
            while (true) {
                int m = (i + j) / 2;
                if (m == pos[k]) break;
                else if (m < pos[k]) {
                    if (p[m] > k) b++;
                    else bb++;
                    i = m + 1;
                } else {
                    if (p[m] < k) f++;
                    else ff++;
                    j = m - 1;
                }
            }

            if (b > k - 1 - bb) {
                cout << "-1 ";
                continue;
            }

            if (f > n - k - ff) {
                cout << "-1 ";
                continue;
            }

            cout << b + f + max(b, f) - min(b, f) << " ";
        }
        cout << "\n";
    }
}