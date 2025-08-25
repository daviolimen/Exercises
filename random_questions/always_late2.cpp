#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

#define MAXN 100

int n, m, dist1[MAXN], dist2[MAXN];
vector<pi> graph[MAXN];

void dijkstra(int start, int end) {
    for (int i = 0; i < MAXN; i++) {
        dist1[i] = dist2[i] = INT_MAX;
    }

    priority_queue<pi, vector<pi>, greater<pi>> heap;
    heap.emplace(0, start);

    while (!heap.empty()) {
        auto [cost, u] = heap.top(); heap.pop();

        if (dist2[u] != INT_MAX) continue;

        if (dist1[u] == INT_MAX) dist1[u] = cost;
        else if (dist2[u] == INT_MAX) dist2[u] = cost;

        for (auto [v, c] : graph[u]) {
            if (dist2[v] != INT_MAX) continue;
            heap.emplace(cost + c, v);
        }
    }
    if (dist2[end] == INT_MAX) printf("?\n");
    else printf("%d\n", dist2[end]);
}

int main() {
    int ctr = 1;
    while (scanf("%d %d", &n, &m) != EOF) {
        for (int i = 0; i < MAXN; i++) graph[i].clear();

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