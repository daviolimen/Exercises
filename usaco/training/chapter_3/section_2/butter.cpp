/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: butter
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

bool visited[801];
int n, p, c, cows[501], dist[801], somas[801];
vector<pair<int, int>> graph[801];

void dijkstra(int start) {
    memset(dist, 0x3f3f3f3f, sizeof(dist));
    memset(visited, 0, sizeof(visited));
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, start);

    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();

        if (visited[u]) continue;
        visited[u] = 1;

        for (auto [v, w] : graph[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }

    for (int i = 1; i <= p; i++) somas[i] += dist[i];
}

int main() {
    ifstream cin ("butter.in");
    ofstream cout ("butter.out");
    cin >> n >> p >> c;
    for (int i = 0; i < n; i++) cin >> cows[i];
    for (int i = 0; i < c; i++) {
        int u, v, w; cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    for (int i = 0; i < n; i++) {
        dijkstra(cows[i]);
    }

    int ans = 0x3f3f3f3f;

    for (int i = 1; i <= p; i++) ans = min(ans, somas[i]);

    cout << ans << "\n";
}