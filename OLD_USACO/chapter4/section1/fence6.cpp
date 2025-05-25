/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: fence6
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int len;
    set<int> lado[2];
};

int N;
bool visited[101];
Edge edges[101];

int dijkstra(int start) {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.emplace(0, start, 0);

    memset(visited, 0, sizeof(visited));

    while (!pq.empty()) {
        auto [cost, u, sid] = pq.top();
        pq.pop();

        if ((u == start) && (cost > 0)) return cost;

        if (visited[u]) continue;
        visited[u] = 1;

        
        for (auto v : edges[u].lado[sid]) {
            if (edges[v].lado[0].find(u) == edges[v].lado[0].end()) {
                pq.emplace(cost + edges[v].len, v, 0);
            } else {
                pq.emplace(cost + edges[v].len, v, 1);
            }
        }
    }

    return -1;
}

int main() {
    ifstream cin ("fence6.in");
    ofstream cout ("fence6.out");
    cin >> N;
    for (int i = 0; i < N; i++) {
        int id; cin >> id;
        cin >> edges[id].len;
        int l, r; cin >> l >> r;
        for (int j = 0; j < l; j++) {
            int x; cin >> x;
            edges[id].lado[0].insert(x);
        }
        for (int j = 0; j < r; j++) {
            int x; cin >> x;
            edges[id].lado[1].insert(x);
        }
    }

    int ans = INT_MAX;
    for (int i = 1; i <= N; i++) {
        int curr = dijkstra(i);
        if (curr == -1) continue;
        ans = min(ans, curr);
    }

    cout << ans << "\n";
}