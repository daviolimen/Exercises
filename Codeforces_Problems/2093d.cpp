#include <bits/stdc++.h>
using namespace std;

#define int long long

int check(int cmp, int x, int y) {
    if ((x <= cmp) && (y <= cmp)) return 0;
    if ((x > cmp) && (y > cmp)) return 1;
    if ((x > cmp) && (y <= cmp)) return 2;
    if ((x <= cmp) && (y > cmp)) return 3;
}

void check2(int v, int cmp, int &x, int &y) {
    if (v <= cmp * cmp) return;
    if (v <= 2 * cmp * cmp) {
        x += cmp;
        y += cmp;
        return;
    }
    if (v <= 3 * cmp * cmp) {
        x += cmp;
        return;
    }
    if (v <= 4 * cmp * cmp) {
        y += cmp;
        return;
    }
}

int32_t main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, q; cin >> n >> q;
        while (q--) {
            string op; cin >> op;
            if (op == "->") {
                int x, y; cin >> x >> y;
                int ans = 1, cmp = (1LL << (n - 1));
                while (cmp > 0) {
                    ans += cmp * cmp * check(cmp, x, y);
                    x %= cmp;
                    if (x == 0) x = cmp;
                    y %= cmp;
                    if (y == 0) y = cmp;
                    cmp >>= 1;
                }
                cout << ans << "\n";
            } else {
                int d; cin >> d;
                int x = 1, y = 1, cmp = (1LL << (n - 1));
                while (cmp > 0) {
                    check2(d, cmp, x, y);
                    d %= (cmp * cmp);
                    if (d == 0) d = cmp * cmp;
                    cmp >>= 1;
                }
                cout << x << " " << y << "\n";
            }
        }
    }
}