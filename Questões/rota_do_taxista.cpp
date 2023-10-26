#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

#define INF 0x3f3f3f3f
#define MAXN 10001
#define MAXK 17

int n, m, k, dist[MAXN], mat[MAXK][MAXK];
vector<pi> graph[MAXN];
bool visited[MAXN];

void dijkstra(int start) {
    memset(visited, 0, sizeof(visited));

    memset(dist, INF, sizeof(dist));
    dist[start] = 0;

    priority_queue<pi, vector<pi>, greater<pi>> heap;
    heap.emplace(0, start);

    while (!heap.empty()) {
        int cost, u; tie(cost, u) = heap.top();
        heap.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto V : graph[u]) {
            int v, w; tie(v, w) = V;
            if (visited[v]) continue;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                heap.emplace(dist[v], v);
            }
        }
    }
}

int main() {
    cin >> n >> m >> k;
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }

    int corridas[MAXK][2];
    for (int i = 1; i <= k; i++) {
        cin >> corridas[i][0] >> corridas[i][1];
    }

    dijkstra(1);
    for (int i = 1; i <= k; i++) {
        mat[0][i] = mat[i][0] = dist[corridas[i][0]];
    }

    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            int d = 0;
            dijkstra(corridas[i][0]);
            d += dist[corridas[i][1]];
            dijkstra(corridas[i][1]);
            d += dist[corridas[j][0]];
        }
    }

    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= k; j++) {
            cout << mat[i][j] << " \n"[j == k];
        }
    }
}