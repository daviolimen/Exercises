#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define MAXN 150

int n, m, q, dist[MAXN][MAXN];
vector<tuple<int, int, int>> edges;

void bellmanFord(int start) {
    dist[start][start] = 0;

    for (int i = 0; i < (n - 1); i++) {
        for (auto [u, v, w] : edges) {
            if (dist[start][v] > dist[start][u] + w) {
                dist[start][v] = dist[start][u] + w;
            }
        }
    }
    for (auto [u, v, w] : edges) {
        if (dist[start][v] > dist[start][u] + w) {
            dist[start][v] = -INF;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    bool nLine = false;
    cin >> n >> m >> q;
    while (n != 0) {
        if (nLine) cout << "\n";
        else nLine = true;

        memset(dist, INF, sizeof(dist));
        edges.clear();

        int u, v, w;
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            edges.emplace_back(u, v, w);
        }

        for (int i = 0; i < n; i++) {
            bellmanFord(i);
        }

        int a, b;
        while (q--) {
            cin >> a >> b;
            if (dist[a][b] == INF) cout << "Impossible\n";
            else if (dist[a][b] == -INF) cout << "-Infinity\n";
            else cout << dist[a][b] << "\n";
        }

        cin >> n >> m >> q;
    }
}