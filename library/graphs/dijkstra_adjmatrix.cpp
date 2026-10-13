#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000

int n, m, dist[MAXN], graph[MAXN][MAXN];
bool visited[MAXN];

int minDist() {
    int min = INT_MAX, min_index;
    
    for (int v = 0; v < n; v++) {
        if ((!visited[v]) && (dist[v] < min)) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int start) {
    fill(dist, dist + MAXN, INT_MAX);
    dist[start] = 0;

    for (int i = 0; i < (n - 1); i++) {
        int u = minDist();
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if ((!visited[v]) && (graph[u][v]) && (dist[u] != INT_MAX) && (dist[v] > dist[u] + graph[u][v])) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
}

int main() {
    cin >> n >> m;
    int u, v, p;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> p;
        graph[u][v] = graph[v][u] = p;
    }
}