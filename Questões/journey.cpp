#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001

int n;
double ans = 0;
vector<int> graph[MAXN];

void dfs(int x, int p, int l, double prob) {
    if (graph[x].size() == 1) {
        ans += prob * (double) l;
        return;
    }
    for (auto v : graph[x]) {
        if (v == p) continue;
        dfs(v, x, l + 1, prob / (graph[x].size() - 1));
    }
}

int main() {
    cin >> n;
    int u, v;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    graph[1].push_back(0);
    graph[0].push_back(1);

    dfs(1, 0, 0, 1);
    printf("%.10lf\n", ans);
}