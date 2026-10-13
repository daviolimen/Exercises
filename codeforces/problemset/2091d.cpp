#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m, k, byRow;

bool check(int x) {
    int div = m / (x + 1);
    int mod = m % (x + 1);
    if (div * x + mod >= byRow) return true;
    return false;
}

int search() {
    int l = 0, r = m;
    while (r - l > 1) {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid;
    }
    return r;
}

int32_t main() {
    ios::sync_with_stdio(false); ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        cin >> n >> m >> k;
        byRow = (k + n - 1) / n;
        int ans = search();
        cout << ans << "\n";
    }
}