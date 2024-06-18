#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;

int n, m;
vector<int> cycle, graph[MAXN];
bool visited[MAXN];

bool dfs(int u) {
    visited[u] = 1;
    for (auto v : graph[u]) {
        cycle.push_back(u);
        if (!visited[v]) {
            if (dfs(v)) return 1;
        } else {
            cycle.push_back(v);
            return 1;
        }
        cycle.pop_back();
    }
    return 0;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        if (dfs(i)) {
            vector<int> ans = {*cycle.rbegin()};
            for (auto it = cycle.rbegin() + 1; it != cycle.rend(); it++) {
                ans.push_back(*it);
                if ((*it) == (*cycle.rbegin())) break;
            }
            cout << (int) ans.size() << "\n";
            reverse(ans.begin(), ans.end());
            for (auto x : ans) cout << x << " ";
            cout << "\n";
        } else {
            cout << "IMPOSSIBLE\n";
        }
        return
    }
}