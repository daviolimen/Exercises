#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;

const int MAXN = 100001;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = int(1e9) + 7;

int n, m, minF[MAXN], maxF[MAXN];
ll dist[MAXN], num[MAXN];
vector<pli> graph[MAXN];
bool visited[MAXN];

void dijkstra(int start, int end) {
    fill(dist, dist + MAXN, INF);
    dist[start] = 0;

    num[start] = 1;

    priority_queue<pli, vector<pli>, greater<pli>> heap;
    heap.emplace(0, start);

    while (!heap.empty()) {
        auto [cost, u] = heap.top(); heap.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto [v, c] : graph[u]) {
            if (dist[v] > dist[u] + c) {
                dist[v] = dist[u] + c;
                minF[v] = minF[u] + 1;
                maxF[v] = maxF[u] + 1;
                num[v] = num[u];
            } else if (dist[v] == dist[u] + c) {
                minF[v] = min(minF[v], minF[u] + 1);
                maxF[v] = max(maxF[v], maxF[u] + 1);
                num[v] += num[u];
            }
            num[v] %= MOD;
            heap.emplace(cost + c, v);
        }
    }
    cout << dist[end] << " " << num[end] << " " << minF[end] << " " << maxF[end] << "\n";
}

int main() {
    cin >> n >> m;
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
    }
    dijkstra(1, n);
}