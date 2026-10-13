#include <bits/stdc++.h>
using namespace std;

#define MAXN 100100

bool visited[MAXN];
int n, m, dist[MAXN];
vector<pair<int, int>> graph[MAXN];

int dijkstra(int start, int end) {
    fill(dist, dist + n, 0x3f3f3f3f);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, start);

    while (pq.size()) {
        auto [cost, u] = pq.top();
        pq.pop();

        if (visited[u]) continue;
        visited[u] = 1;

        if (u == end) return cost;

        for (auto [v, c] : graph[u]) {
            if (dist[v] > dist[u] + c) {
                dist[v] = dist[u] + c;
                pq.emplace(dist[v], v);
            }
        }
    }

    return -1;
}

int main() {

}