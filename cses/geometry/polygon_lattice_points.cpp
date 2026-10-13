#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    int n; cin >> n;
    vector<pair<int, int>> pts(n);
    for (int i = 0; i < n; i++) cin >> pts[i].first >> pts[i].second;

    int area = 0, borderPoints = 0;

    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += (pts[i].first * pts[j].second) - (pts[i].second * pts[j].first);
        borderPoints += gcd(abs(pts[i].first - pts[j].first), abs(pts[i].second - pts[j].second));
    }

    area = abs(area);

    int insidePoints = area - borderPoints + 2;
    insidePoints /= 2;

    cout << insidePoints << " " << borderPoints << "\n";
}