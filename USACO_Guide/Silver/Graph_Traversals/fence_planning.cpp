#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001

int n, m;
bool visited[MAXN];
pair<int, int> cows[MAXN];
vector<int>  graph[MAXN], comp;

void dfs(int u) {
    if (visited[u]) return;
    comp.push_back(u);
    visited[u] = true;
    for (auto v : graph[u]) {
        dfs(v);
    }
}

int main() {
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> cows[i].first >> cows[i].second;
    }
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int ans = INT_MAX;

    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        dfs(i);
        int minx = INT_MAX, maxx = -1, miny = INT_MAX, maxy = -1;
        for (auto x : comp) {
            minx = min(minx, cows[x].first);
            maxx = max(maxx, cows[x].first);
            miny = min(miny, cows[x].second);
            maxy = max(maxy, cows[x].second);
        }
        ans = min(ans, 2 * (maxx - minx + maxy - miny));
        comp.clear();
    }

    cout << ans << "\n";
}