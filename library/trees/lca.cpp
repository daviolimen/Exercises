#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001
#define MAXLOG 18

int n, ancestral[MAXLOG][MAXN], nivel[MAXN];
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
    if (nivel[v] > nivel[u]) swap(u, v); // assumimos que u esta mais embaixo

    for (int i = MAXLOG - 1; i >= 0; --i) {
        if (nivel[u] - (1 << i) >= nivel[v]) u = ancestral[i][u];
    }

    if (u == v) return v;

    for (int i = MAXLOG - 1; i >= 0; --i) {
        if ((ancestral[i][u] != -1) && (ancestral[i][u] != ancestral[i][v])) {
            u = ancestral[i][u];
            v = ancestral[i][v];
        }
    }

    return ancestral[0][u];
}

int main() {
    cin >> n;
    int a, b;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    memset(ancestral, -1, sizeof(ancestral));
    memset(nivel, -1, sizeof(nivel));

    nivel[1] = 0;
    dfs(1);

    for (int i = 1; i < MAXLOG; i++) {
        for (int j = 1; j <= n; j++) {
            if (ancestral[i - 1][j] != -1) {
                ancestral[i][j] = ancestral[i - 1][ancestral[i - 1][j]];
            }
        }
    }
}