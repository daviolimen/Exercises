#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> ti;

#define MAXN 1000
#define MAXM 10000
#define INF 0x3f3f3f3f

int n, m, dist[MAXN];
vector<ti> edges(MAXM);

void bellmanFord(int start) {
    fill(dist, dist + MAXN, INF);
    dist[start] = 0;

    for (int i = 0; i < (n - 1); i++) {
        for (auto [u, v, w] : edges) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    int u, v, w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
    }
    bellmanFord(0);
    for (int i = 0; i < n; i++) {
        cout << dist[i] << " \n"[i == (n - 1)];
    }
}