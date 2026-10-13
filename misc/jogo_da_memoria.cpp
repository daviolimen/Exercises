#include <bits/stdc++.h>
using namespace std;

#define MAXN 50001
#define MAXLOG 17
#define MAXC 25001

int n, C[MAXN], nivel[MAXN], ancestral[MAXLOG][MAXN];
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
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> C[i];
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

    int ans = 0, memo[MAXC];
    memset(memo, 0, sizeof(memo));
    for (int i = 1; i <= n; i++) {
        if (memo[C[i]]) {
            ans += nivel[i] + nivel[memo[C[i]]] - 2 * nivel[lca(i, memo[C[i]])];
        } else {
            memo[C[i]] = i;
        }
    }

    cout << ans << "\n";
}