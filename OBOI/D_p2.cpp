#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

const int MAXN = 100001, MAXK = 10000, MAXLOG = 18;

int N, M, K, atr[MAXK], nivel[MAXN], dist[MAXN], ancestral[MAXLOG][MAXN];
vector<pi> graph[MAXN];

void dfs(int u) {
    for (auto [v, c] : graph[u]) {
        if (nivel[v] != -1) continue;
        ancestral[0][v] = u;
        nivel[v] = nivel[u] + 1;
        dist[v] = dist[u] + c;
        dfs(v);
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
    cin >> N >> M >> K;
    for (int i = 0; i < K; i++) cin >> atr[i];
    for (int i = 0; i < M; i++) {
        int u, v, p; cin >> u >> v >> p;
        graph[u].emplace_back(v, p);
        graph[v].emplace_back(u, p);
    }

    memset(nivel, -1, sizeof(nivel));
    memset(ancestral, -1, sizeof(ancestral));

    nivel[1] = 0;
    dfs(1);

    for (int i = 1; i < MAXLOG; i++) {
        for (int j = 1; j <= N; j++) {
            if (ancestral[i - 1][j] == -1) continue;
            ancestral[i][j] = ancestral[i - 1][ancestral[i - 1][j]];
        }
    }

    int ans = INT_MAX;

    for (int i = )

    cout << ans << "\n";
}