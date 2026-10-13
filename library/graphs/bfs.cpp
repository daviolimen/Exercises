#include <bits/stdc++.h>
using namespace std;

#define MAXN 1010

int N, M;
vector<int> graph[MAXN];
bool visited[MAXN];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int vertex = q.front();
        q.pop();
        for (auto neighbor : graph[vertex]) {
            if (visited[neighbor]) continue;
            visited[neighbor] = true;
            q.push(neighbor);
        }
    }
}

int main() {

}