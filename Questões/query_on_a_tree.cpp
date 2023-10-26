#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

#define MAXN 10001
#define MAXLOG 15

int n, nivel[MAXN], dist[MAXN], ancestral[MAXLOG][MAXN];
vector<pi> graph[MAXN];

void dfs(int u) {
    for (auto [v, c] : graph[u]) {
        if (nivel[v] == -1) {
            ancestral[0][v] = u;
            dist[v] = dist[u] + c;
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

int getKthNode(int a, int b, int k) {
    int c = lca(a, b), d = nivel[a] + nivel[b] - 2 * nivel[c];
    k--;
    if (c == a) {
        k = d - k;
        for (int i = 0; i < MAXLOG; i++) {
            if (k & (1 << i)) b = ancestral[i][b];
        }
        return b;
    } else if (c == b) {
        for (int i = 0; i < MAXLOG; i++) {
            if (k & (1 << i)) a = ancestral[i][a];
        }
        return a;
    } else if (k <= nivel[a] - nivel[c]) {
        for (int i = 0; i < MAXLOG; i++) {
            if (k & (1 << i)) a = ancestral[i][a];
        }
        return a;
    } else {
        k = d - k;
        for (int i = 0; i < MAXLOG; i++) {
            if (k & (1 << i)) b = ancestral[i][b];
        }
        return b;
    }
}

int main() {
    ios::sync_with_stdio(false); ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int tt; cin >> tt;
    while (tt--) {
        for (int i = 0; i < MAXN; i++) graph[i].clear();
        memset(nivel, -1, sizeof(nivel));
        memset(ancestral, -1, sizeof(ancestral));

        cin >> n;
        for (int i = 1; i < n; i++) {
            int a, b, c; cin >> a >> b >> c;
            graph[a].emplace_back(b, c);
            graph[b].emplace_back(a, c);
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

        string op;
        cin >> op;
        while (op != "DONE") {
            if (op == "DIST") {
                int a, b; cin >> a >> b;
                cout << (dist[a] + dist[b] - 2 * dist[lca(a, b)]) << "\n";
            } else if (op == "KTH") {
                int a, b, c; cin >> a >> b >> c;
                cout << getKthNode(a, b, c) << "\n";
            }
            cin >> op;
        }
        cout << "\n";
    }
}