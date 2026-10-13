#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200010;

int n, pai[MAXN], dist[2][MAXN];
vector<int> graph[MAXN];

void dfs(int u, int p, int d, int q) {
    dist[q][u] = d;
    pai[u] = p;
    for (auto v : graph[u]) {
        if (v == p) continue;
        dfs(v, u, d + 1, q);
    }
}

int findCentroid() {
    dfs(1, 0, 0, 0);

    int x, y, best = 0;

    for (int i = 1; i <= n; i++) {
        if (dist[0][i] > best) {
            best = dist[0][i];
            x = i;
        }
    }

    dfs(x, 0, 0, 0);

    best = 0;

    for (int i = 1; i <= n; i++) {
        if (dist[0][i] > best) {
            best = dist[0][i];
            y = i;
        }
    }

    dfs(y, 0, 0, 1);

    int u = x, mn = INT_MAX, c = u;

    while (u) {
        if (max(dist[0][u], dist[1][u]) < mn) {
            mn = max(dist[0][u], dist[1][u]);
            c = u;
        }
        u = pai[u];
    }

    return c;
}

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cout << findCentroid() << "\n";
}