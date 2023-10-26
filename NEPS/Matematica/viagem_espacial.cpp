#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline pair<ll, ll> sqrDist(ll x0, ll y0, ll x1, ll y1, ll x2, ll y2) {
    return {(abs((x2 - x1) * (y1 - y0) - (x1 - x0) * (y2 - y1)) * abs((x2 - x1) * (y1 - y0) - (x1 - x0) * (y2 - y1))), ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1))};
}

int main() {
    ll n, xc, yc, r;
    cin >> n >> xc >> yc >> r;

    int ans = 0;

    while (n--) {
        ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

        auto [num, dem] = sqrDist(xc, yc, x1, y1, x2, y2);

        if (num <= dem * r * r) ans++;
    }

    cout << ans << "\n";
}