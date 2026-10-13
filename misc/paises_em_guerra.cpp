#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

#define MAXN 501
#define INF 500001

int n, m, graph[MAXN][MAXN], dist[MAXN][MAXN];

void floydWarshall() {
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
    int ctr = 0;
    while (n != 0) {
        if (ctr) {
            cout << "\n";
        } else {
            ctr = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                (i == j) ? graph[i][j] = 0 : graph[i][j] = INF;
            }
        }
        int x, y, h;
        for (int i = 0; i < m; i++) {
            cin >> x >> y >> h;
            x--; y--;
            if (graph[y][x] != INF) {
                graph[x][y] = 0;
                graph[y][x] = 0;
            } else {
                graph[x][y] = h;
            }
        }

        floydWarshall();

        int k;
        cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            x--; y--;
            if (dist[x][y] >= INF) cout << "Nao e possivel entregar a carta\n";
            else cout << dist[x][y] << "\n";
        }

        cin >> n >> m;
    }
}