#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
pair<int, int> pts[1010];

int32_t main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> pts[i].first >> pts[i].second;
    pts[n] = pts[0];
    
    int area = 0;

    for (int i = 0; i < n; i++) {
        area += ((pts[i + 1].first * pts[i].second) - (pts[i].first * pts[i + 1].second));
    }

    cout << abs(area) << "\n";
}