#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define MAXN 100000
#define MAXLOG 18

int n, nivel[MAXN], ancestral[MAXLOG][MAXN];
ll dist[MAXN];
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
    cin >> n;
    while (n != 0) {
        for (int i = 0; i < MAXN; i++) graph[i].clear();

        int a, l;
        for (int i = 1; i < n; i++) {
            cin >> a >> l;
            graph[i].emplace_back(a, l);
            graph[a].emplace_back(i, l);
        }

        fill(nivel, nivel + MAXN, -1);
        memset(ancestral, -1, sizeof(ancestral));

        dist[0] = 0;
        nivel[0] = 0;
        dfs(0);

        for (int i = 1; i < MAXLOG; i++) {
            for (int j = 0; j < n; j++) {
                if (ancestral[i - 1][j] != -1) {
                    ancestral[i][j] = ancestral[i - 1][ancestral[i - 1][j]];
                }
            }
        }

        int q, s, t;
        cin >> q;

        while (q--) {
            cin >> s >> t;
            cout << (dist[s] + dist[t] - 2 * dist[lca(s, t)]) << " \n"[q == 0];
        }

        cin >> n;
    }
}