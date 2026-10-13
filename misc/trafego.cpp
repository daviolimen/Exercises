#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

const int MAXN = 50001;

struct sema {
    int v, d, g, r;
    sema (int _v, int _d, int _g, int _r) {
        v = _v;
        d = _d;
        g = _g;
        r = _r;
    }
};

int n, m;
vector<sema> graph[MAXN];
bool visited[MAXN];

int dijkstra(int start, int end) {
    priority_queue<pi, vector<pi>, greater<pi>> heap;
    heap.emplace(0, start);

    while (!heap.empty()) {
        auto [time, u] = heap.top(); heap.pop();

        if (visited[u]) continue;
        visited[u] = true;

        if (u == end) return time;

        for (auto s : graph[u]) {
            int newTime = time + s.d;
            if ((newTime % (s.g + s.r)) < s.g) {
                heap.emplace(newTime, s.v);
            } else {
                newTime += (s.g + s.r) - (newTime % (s.g + s.r));
                heap.emplace(newTime, s.v);
            }
        }
    }
    return -1;
}

int main() {
    cin >> n >> m;
    int a, b, d, g, r;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> d >> g >> r;
        graph[a].emplace_back(b, d, g, r);
    }
    cout << dijkstra(1, n) << "\n";
}