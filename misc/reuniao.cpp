#include <bits/stdc++.h>
using namespace std;

#define MAXN 100
#define INF 10000000

int n, m, graph[MAXN][MAXN], dist[MAXN][MAXN];

void floyd_warshall() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    int u, v, w;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) graph[i][j] = 0;
            else graph[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }
    floyd_warshall();
    int min_max_dist = INF;
    for (int i = 0; i < n; i++) {
        min_max_dist = min(min_max_dist, *max_element(dist[i], dist[i] + n));
    }
    cout << min_max_dist << "\n";
}