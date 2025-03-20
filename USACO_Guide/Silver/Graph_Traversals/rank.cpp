#include <bits/stdc++.h>
using namespace std;

const int MAXN = 21;

bool inCycle[MAXN];
int n, m, timer, tin[MAXN], tout[MAXN], parent[MAXN];
vector<int> graph[MAXN];

void dfs(int u, int p) {
    if (tin[u]) return;
    tin[u] = timer++;
    parent[u] = p;
    for (auto v : graph[u]) {
        if (tin[v] == 0) dfs(v, u);
        else {
            if (tout[v] == 0) {
                inCycle[v] = 1;
                int cur = u;
                while (cur != v) {
                    inCycle[cur] = 1;
                    cur = parent[cur];
                }
            }
        }
    }
    tout[u] = timer;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, sa, sb; cin >> a >> b >> sa >> sb;
        if (sa > sb) graph[a].push_back(b);
        else graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (tin[i]) continue;
        dfs(i, -1);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (inCycle[i]) ans++;
    }
    cout << ans << "\n";
}