#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

#define MAXN 100

int n, m;
vector<int> dist[MAXN];
vector<pi> graph[MAXN];

void dijkstra(int start, int end) {
    for (int i = 0; i < MAXN; i++) dist[i].clear();

    priority_queue<pi, vector<pi>, greater<pi>> heap;
    heap.emplace(0, start);

    while (!heap.empty()) {
        auto curr = heap.top();
        heap.pop();

        if (dist[curr.second].size() == 0) dist[curr.second].push_back(curr.first);
        else if (dist[curr.second].back() != curr.first) dist[curr.second].push_back(curr.first);

        if (dist[curr.second].size() > 2) continue;

        for (auto V : graph[curr.second]) {
            if (dist[V.first].size() == 2) continue;
            heap.emplace(V.second + curr.first, V.first);
        }
    }
    if (dist[end].size() < 2) printf("?\n");
    else printf("%d\n", dist[end][1]);
}

int main() {
    int ctr = 1;
    while (scanf("%d %d", &n, &m) != EOF) {

        for (int i = 0; i < MAXN; i++) {
            graph[i].clear();
        }

        int a, b, c;
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &a, &b, &c);
            graph[a].emplace_back(b, c);
            graph[b].emplace_back(a, c);
        }

        int q, s, d;
        scanf("%d", &q);
        printf("Set #%d\n", ctr++);
        while (q--) {
            scanf("%d %d", &s, &d);
            dijkstra(s, d);
        }
    }
}