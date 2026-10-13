#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001

int n, m, color[MAXN];
vector<int> graph[MAXN];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (color[i] != 0) continue;

        color[i] = 1;
        queue<int> q;
        q.push(i);

        while (!q.empty()) {
            int u = q.front(); q.pop();

            for (auto v : graph[u]) {
                if (color[v] == 0) {
                    q.push(v);
                    color[v] = 3 - color[u];
                } else {
                    if (color[v] != (3 - color[u])) {
                        cout << "IMPOSSIBLE\n";
                        return 0;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << color[i] << " \n"[i == n];
    }
}