#include <bits/stdc++.h>
using namespace std;

#define MAXN 16

int n, dist[MAXN][MAXN];
pair<int, int> pts[MAXN];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> pts[i].first;
    for (int i = 0; i < n; i++) cin >> pts[i].second;

    int ans = INT_MAX;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            dist[i][j] = abs(pts[j].first - pts[i].first) + abs(pts[j].second - pts[i].second);
        }
    }

    for (int mask = 0; mask < (1 << n); mask++) {
        int maior = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((mask & (1 << i)) && (mask & (1 << j))) {
                    maior = max(maior, dist[i][j]);
                }
                if (((mask & (1 << i)) == 0) && ((mask & (1 << j)) == 0)) {
                    maior = max(maior, dist[i][j]);
                }
            }
        }

        ans = min(ans, maior);
    }

    cout << ans << "\n";
}