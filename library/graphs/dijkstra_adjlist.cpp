#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

#define MAXN 100010

int n, m, dist[MAXN];
bool visited[MAXN];
vector<pi> graph[MAXN];

void dijkstra(int start) {
    fill(dist + 1, dist + n + 1, INT_MAX);
    dist[start] = 0;

    priority_queue<pi, vector<pi>, greater<pi>> heap;

    heap.emplace(0, start);

    while (!heap.empty()) {
        int u = heap.top().second;
        heap.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto V : graph[u]) {
            int v, w; tie(v, w) = V;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                heap.emplace(dist[v], v);
            }
        }
    }
}



int main() {}