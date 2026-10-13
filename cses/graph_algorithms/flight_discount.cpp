#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<ll, bool, int> tlbi;

const ll INF = 1e15;
#define MAXN 100001

int n, m;
ll dist[MAXN][2];
vector<pi> graph[MAXN];

ll dijkstra() {
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < 2; j++) {
            dist[i][j] = INF;
        }
    }
    dist[1][0] = dist[1][1] = 0;

    priority_queue<tlbi, vector<tlbi>, greater<tlbi>> heap;
    heap.emplace(0, false, 1);

    while (!heap.empty()) {
        ll cost; bool used; int u; tie(cost, used, u) = heap.top();
        heap.pop();

        if (cost != dist[u][used]) continue;
        if (u == n) break;

        for (auto [v, w] : graph[u]) {
            if (!used) {
                if (dist[u][used] + (w / 2) < dist[v][1]) {
                    dist[v][1] = dist[u][used] + (w / 2);
                    heap.emplace(dist[v][1], true, v);
                }
            }
            if (dist[u][used] + w < dist[v][used]) {
                dist[v][used] = dist[u][used] + w;
                heap.emplace(dist[v][used], used, v);
            }
        }
    }
    return dist[n][1];
}

int main() {
    cin >> n >> m;
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
    }
    cout << dijkstra() << "\n";
}