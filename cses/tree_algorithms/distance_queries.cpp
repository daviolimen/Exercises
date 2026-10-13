#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200001, MAXLOG = 19;

int n, nivel[MAXN], ancestral[MAXLOG][MAXN];
vector<int> graph[MAXN];

void dfs(int u, int p) {
    for (auto v : graph[u]) {
        if (v == p) continue;
        ancestral[0][v] = u;
        nivel[v] = nivel[u] + 1;
        dfs(v, u);
    }
}

int lca(int u, int v) {
    if (nivel[u] < nivel[v]) swap(u, v);

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
    ios::sync_with_stdio(false); ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int q; cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, -1);

    for (int i = 1; i < MAXLOG; i++) {
        for (int j = 1; j <= n; j++) {
            if (ancestral[i - 1][j] != -1) {
                ancestral[i][j] = ancestral[i - 1][ancestral[i - 1][j]];
            }
        }
    }

    while (q--) {
        int a, b; cin >> a >> b;
        cout << (nivel[a] + nivel[b] - 2 * nivel[lca(a, b)]) << "\n";
    }
}