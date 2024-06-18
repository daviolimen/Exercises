#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

const int MAXN = 200001;

int n, m, dist[MAXN];
vector<pi> graph[MAXN];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }

    memset(dist, 0x3f3f3f3f, sizeof(dist));

    deque<int> q;
    q.push_front(1);
    dist[1] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop_front();

        for (auto [v, c] : graph[u]) {
            if (dist[v] > dist[u] + c) {
                dist[v] = dist[u] + c;
                if (c == 0) q.push_front(v);
                else q.push_back(v);
            }
        }
    }

    
}