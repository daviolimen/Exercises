#include <bits/stdc++.h>
using namespace std;

#define MAXN 1010

int N, M;
vector<int> graph[MAXN];
bool visited[MAXN];

void dfs(int start) {
    visited[start] = true;
    for (auto neighbor : graph[start]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {

}