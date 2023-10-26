#include <bits/stdc++.h>
using namespace std;

#define MAXN 1001
#define MAXLOG 11

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
    ios::sync_with_stdio(false); ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    for (int C = 1; C <= tt; C++) {
        for (int i = 0; i < MAXN; i++) graph[i].clear();
        memset(nivel, -1, sizeof(nivel));
        memset(ancestral, -1, sizeof(ancestral));

        cin >> n;
        int m, a;
        for (int i = 1; i <= n; i++) {
            cin >> m;
            for (int j = 0; j < m; j++) {
                cin >> a;
                graph[i].push_back(a);
                graph[a].push_back(i);
            }
        }

        nivel[1] = 0;
        dfs(1);

        for (int i = 1; i < MAXLOG; i++) {
            for (int j = 1; j <= n; j++) {
                if (ancestral[i - 1][j] != -1) {
                    ancestral[i][j] = ancestral[i - 1][ancestral[i - 1][j]];
                }
            }
        }

        cout << "Case " << C << ":\n";
        int q, v, w; cin >> q;
        while (q--) {
            cin >> v >> w;
            cout << lca(v, w) << "\n";
        }
    }
}