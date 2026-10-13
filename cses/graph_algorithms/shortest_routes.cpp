#include <bits/stdc++.h>
using namespace std;

const long long MAXN = 501, INF = 0x3f3f3f3f3f3f3f3f;

long long n, m, q, graph[MAXN][MAXN], dist[MAXN][MAXN];

void floydWarshall() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
}

int main() {
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            graph[i][j] = INF;
            dist[i][j] = INF;
        }
    }
    for (int i = 0; i < MAXN; i++) graph[i][i] = 0;
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        long long a, b, c; cin >> a >> b >> c;
        graph[a][b] = min(graph[a][b], c);
        graph[b][a] = min(graph[b][a], c);
    }

    floydWarshall();

    while (q--) {
        int a, b; cin >> a >> b;
        cout << ((dist[a][b] == INF) ? -1 : dist[a][b]) << "\n";
    }
}