#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001

int n, m;
vector<pair<int, char>> graph[MAXN];

int main() {
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        char t; int a, b; cin >> t >> a >> b;
        graph[a].emplace_back(b, t);
        graph[b].emplace_back(a, t);
    }

    int ans = 0;
    vector<int> color(n + 1, -1);

    for (int i = 1; i <= n; i++) {
        if (color[i] != -1) continue;
        color[i] = 0;
        ans++;

        queue<int> q;
        q.push(i);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto [v, c] : graph[u]) {
                if (color[v] == -1) {
                    q.push(v);
                    if (c == 'S') color[v] = color[u];
                    else color[v] = color[u] ^ 1;
                } else {
                    if (((c == 'S') && (color[u] != color[v])) || ((c == 'D') && (color[u] == color[v]))) {
                        cout << "0\n";
                        return 0;
                    }
                }
            }
        }
    }

    cout << "1";
    for (int i = 0; i < ans; i++) cout << "0";
    cout << "\n";
}