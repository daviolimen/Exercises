#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001

int n, m;
vector<int> graph[MAXN], cycle;
bool visited[MAXN];

bool dfs(int u, int p) {
    visited[u] = 1;
    for (auto v : graph[u]) {
        cycle.push_back(v);
        if (!visited[v]) {
            if (dfs(v, u)) return 1;
        } else if (v != p) return 1;
        cycle.pop_back();
    }
    return 0;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        cycle.push_back(i);
        if ((!visited[i]) && (dfs(i, 0))) {
            vector<int> ans = {*cycle.rbegin()};
            for (auto j = cycle.rbegin() + 1; j != cycle.rend(); j++) {
                ans.push_back(*j);
                if ((*j) == (*cycle.rbegin())) break;
            }

            cout << ans.size() << "\n";
            for (auto x : ans) cout << x << " ";
            cout << "\n";
            return 0;
        }
        cycle.pop_back();
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}