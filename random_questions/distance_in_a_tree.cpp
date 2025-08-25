#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

#define MAXN 50000
#define MAXLOG 17

int n, nivel[MAXN], dist[MAXN], ancestral[MAXLOG][MAXN];
vector<pi> graph[MAXN];

void dfs(int u) {
    for (auto [v, c] : graph[u]) {
        if (nivel[v] == -1) {
            ancestral[0][v] = u;
            nivel[v] = nivel[u] + 1;
            dist[v] = dist[u] + c;
            dfs(v);
        }
    }
}

int lca(int u, int v) {
    if (nivel[v] > nivel[u]) swap(u, v);

    for (int i = MAXLOG - 1; i >= 0; i--) {
        if (nivel[u]  - (1 << i) >= nivel[v]) u = ancestral[i][u];
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
    ios::sync_with_stdio(false); ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, w; cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    memset(nivel, -1, sizeof(nivel));
    memset(ancestral, -1, sizeof(ancestral));
    nivel[0] = 0;

    dfs(0);

    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        cout << (dist[a] + dist[b] - 2 * dist[lca(a, b)]) << "\n";
    }
}