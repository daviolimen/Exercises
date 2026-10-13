#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
multiset<int> msX, msY;
pair<int, int> pts[200100];

long long solve() {
    int a = *(msX.rbegin()), b = *(msY.rbegin()), c = *(msX.begin()), d = *(msY.begin());

    long long area = (a - c + 1) * (b - d + 1);
    if (n - 1 == area) {
        area = min(area + a - c + 1, area + b - d + 1);
    }
    return area;
}

int32_t main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        msX.clear();
        msY.clear();
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> pts[i].first >> pts[i].second;
            msX.insert(pts[i].first);
            msY.insert(pts[i].second);
        }

        if (n == 1) {
            cout << "1\n";
            continue;
        }

        long long ans = LONG_LONG_MAX;
        for (int i = 0; i < n; i++) {
            msX.erase(msX.find(pts[i].first));
            msY.erase(msY.find(pts[i].second));
            ans = min(ans, solve());
            msX.insert(pts[i].first);
            msY.insert(pts[i].second);
        }
        cout << ans << "\n";
    }

}