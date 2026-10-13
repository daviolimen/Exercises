#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

const int MAXN = 100001;

int n, m, minC[MAXN], minE[MAXN], dist[MAXN], distE[MAXN];
vector<pi> graph[MAXN];
bool visited[MAXN];

void dijkstra(int start) {
    fill(minC, minC + MAXN, INT_MAX);
    fill(minE, minE + MAXN, INT_MAX);
    fill(dist, dist + MAXN, INT_MAX);
    fill(distE, distE + MAXN, INT_MAX);
    minC[start] = minE[start] = dist[start] = distE[start] = 0;

    priority_queue<pi, vector<pi>, greater<pi>> heap;
    heap.emplace(0, start);

    while (!heap.empty()) {
        auto [cost, u] = heap.top();
        heap.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto [v, c] : graph[u]) {
            if (minE[v] > minE[u] + 1) {
                minE[v] = minE[u] + 1;
                distE[v] = distE[u] + c;
            }
            if (dist[v] > dist[u] + c) {
                dist[v] = dist[u] + c;
                minC[v] = minC[u] + 1;
            } else if (dist[v] == dist[u] + c) {
                minC[v] = min(minC[v], minC[u] + 1);
            }
            heap.emplace(cost + c, v);
        }
    }
}

int solve() {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (minC[i] == minE[i]) continue;
        int currK = (distE[i] - dist[i]) / (minC[i] - minE[i]);
        if ((distE[i] - dist[i]) % (minC[i] - minE[i]) != 0) {
            currK++;
        }
        ans = max(ans, currK);
    }
    return ans;
}

int main() {
    cin >> n >> m;
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }
    dijkstra(1);
    int ans = solve();
    if (ans < 0) cout << -1 << "\n";
    else cout << ans << "\n";
}