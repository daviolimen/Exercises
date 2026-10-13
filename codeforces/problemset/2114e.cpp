#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 200100;

int n, dan[MAXN], best[MAXN][2];
vector<int> graph[MAXN];

void dfs(int u, int p) {
    best[u][0] = dan[u] - best[p][1];
    best[u][1] = min(0LL, dan[u] - best[p][0]);
    for (auto v : graph[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
}

int32_t main() {
    int tt; cin >> tt;
    while (tt--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> dan[i];
        for (int i = 1; i < n; i++) {
            int a, b; cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        dfs(1, 0);
        for (int i = 1; i <= n; i++) cout << best[i][0] << " \n"[i == n];

        for (int i = 0; i <= n; i++) {
            best[i][0] = best[i][1] = 0;
            graph[i].clear();
        }
    }
}