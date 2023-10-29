#include <bits/stdc++.h>
using namespace std;

#define MAXN 101

int n, m, limits[MAXN], velocities[MAXN];

int main() {
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    cin >> n >> m;
    int curr = 1;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        for (int j = 0; j < a; j++) {
            limits[curr] = b;
            curr++;
        }
    }
    curr = 1;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        for (int j = 0; j < a; j++) {
            velocities[curr] = b;
            curr++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= 100; i++) {
        ans = max(ans, velocities[i] - limits[i]);
    }

    cout << ans << "\n";

}