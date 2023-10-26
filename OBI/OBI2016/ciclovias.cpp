#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001

int n, m;
vector<int> graph[MAXN], dp[MAXN];

int nextV(int u, int i) {
    return (upper_bound(graph[graph[u][i]].begin(), graph[graph[u][i]].end(), u) - graph[graph[u][i]].begin());
}

int dfs(int u, int i) {
    if (i >= dp[u].size()) return 1;
    if (dp[u][i]) return dp[u][i];
    return dp[u][i] = max(dfs(u, i + 1), 1 + dfs(graph[u][i], nextV(u, i)));
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        dp[a].push_back(0);
        graph[b].push_back(a);
        dp[b].push_back(0);
    }

    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    for (int i = 1; i <= n; i++) {
        cout << dfs(i, 0) << " \n"[i == n];
    }
}