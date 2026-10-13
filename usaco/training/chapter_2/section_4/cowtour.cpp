/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: cowtour
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 160;

double getDist(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int n, ctr, pts[MAXN][2], comp[MAXN];
double dist[MAXN][MAXN];
bool mat[MAXN][MAXN], visited[MAXN];

void dfs(int u) {
    if (visited[u]) return;
    visited[u] = 1;
    comp[u] = ctr;
    for (int i = 0; i < n; i++) {
        if (!mat[u][i]) continue;
        dfs(i);
    }
}

int32_t main() {
    ifstream cin ("cowtour.in");
    ofstream cout ("cowtour.out");
    cin >> n;
    for (int i = 0; i < n; i++) cin >> pts[i][0] >> pts[i][1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c; cin >> c;
            if (c == '1') mat[i][j] = 1;
            else mat[i][j] = 0;
            dist[i][j] = getDist(pts[i][0], pts[i][1], pts[j][0], pts[j][1]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        dfs(i);
        ctr++;
    }

    double floyd[MAXN][MAXN];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) floyd[i][j] = 0;
            else if (mat[i][j]) floyd[i][j] = dist[i][j];
            else floyd[i][j] = 1e15;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                floyd[j][k] = min(floyd[j][k], floyd[j][i] + floyd[i][k]);
            }
        }
    }

    double compDiam[MAXN];
    memset(compDiam, 0, sizeof(compDiam));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (comp[i] != comp[j]) continue;
            int c = comp[i];
            compDiam[c] = max(compDiam[c], floyd[i][j]);
        }
    }

    double ans = 1e15;
    for (int x = 0; x < n; x++) {
        double d1 = 0;
        for (int i = 0; i < n; i++) {
            if (comp[x] == comp[i]) d1 = max(d1, floyd[x][i]);
        }
        for (int y = 0; y < n; y++) {
            if (comp[x] == comp[y]) continue;
            double d2 = 0;
            for (int i = 0; i < n; i++) {
                if (comp[y] == comp[i]) d2 = max(d2, floyd[y][i]);
            }
            ans = min(ans, max({d1 + d2 + dist[x][y], compDiam[comp[x]], compDiam[comp[y]]}));
        }
    }

    cout << fixed << setprecision(6) << ans << "\n";

    return 0;
}