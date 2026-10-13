#include <bits/stdc++.h>
using namespace std;

#define MAXN 1010

int N, M;
vector<int> graph[MAXN];
bool visited[MAXN];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto x : graph[u]) {
            if (visited[x] == false) {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

int main() {
    cin >> N >> M;
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (visited[i] == false) {
            ans++;
            bfs(i);
        }
    }
    cout << ans << "\n";
}