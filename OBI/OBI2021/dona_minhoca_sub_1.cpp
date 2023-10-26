#include <bits/stdc++.h>
using namespace std;

#define MAXN 50001
#define MAXLOG 17

int n, nivel[MAXN], ancestral[MAXLOG][MAXN];
vector<int> graph[MAXN];

void dfs(int u) {
    for (auto v : graph[u]) {
        if (nivel[v] == -1) {
            ancestral[0][v] = u;
            nivel[v] = nivel[u] + 1;
            dfs(v);
        }
    }
}

int lca(int u, int v) {
    if (nivel[v] > nivel[u]) swap(u, v);

    for (int i = MAXLOG - 1; i >= 0; i--) {
        if (nivel[u] - (1 << i) >= nivel[v]) u = ancestral[i][u];
    }

    if (u == v) return u;

    for (int i = MAXLOG - 1; i >= 0; i--) {
        if ((ancestral[i][u] != -1) && (ancestral[i][u] != ancestral[i][v])) {
            u = ancestral[i][u];
            v = ancestral[i][v];
        }
    }

    return ancestral[0][u];
}

int main() {
    memset(nivel, -1, sizeof(nivel));
    memset(ancestral, -1, sizeof(ancestral));
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    nivel[1] = 0;
    dfs(1);

    for (int i = 1; i < MAXLOG; i++) {
        for (int j = 1; j <= n; j++) {
            if (ancestral[i - 1][j] == -1) continue;
            ancestral[i][j] = ancestral[i - 1][ancestral[i - 1][j]];
        }
    }

    int ans = 0, diam = 0;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int d = nivel[i] + nivel[j] - 2 * nivel[lca(i, j)];
            if (d > diam) {
                ans = 1;
                diam = d;
            } else if (d == diam) {
                ans++;
            }
        }
    }

    cout << (diam + 1) << "\n" << ans << "\n";
}