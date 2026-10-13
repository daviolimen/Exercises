#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

#define MAXN 100001

int n, m, pai[MAXN];
vector<int> graph[MAXN];
bool visited[MAXN];

void bfs() {
    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (auto v : graph[u]) {
            if (visited[v]) continue;
            visited[v] = true;
            pai[v] = u;
            q.push(v);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bfs();

    if (pai[n] == 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    int u = n;
    stack<int> st;

    while (u != 1) {
        st.push(u);
        u = pai[u];
    }
    st.push(u);

    cout << st.size() << "\n";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << "\n";
}