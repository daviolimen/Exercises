#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001

int n, dist[MAXN];
vector<int> graph[MAXN];

void dfs(int u, int p) {
    dist[u] = dist[p] + 1;
    for (auto v : graph[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    if (n == 1) {
        cout << "0\n";
        return 0;
    }

    dist[0] = -1;
    dfs(1, 0);

    int bestNode, maxDist = 0;

    for (int i = 1; i <= n; i++) {
        if (dist[i] > maxDist) {
            bestNode = i;
            maxDist = dist[i];
        }
    }

    dfs(bestNode, 0);

    for (int i = 1; i <= n; i++) {
        if (dist[i] > maxDist) {
            bestNode = i;
            maxDist = dist[i];
        }
    }

    cout << maxDist << "\n";
}