#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> ti;

#define MAXN 100

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

int n;
bool grid[MAXN][MAXN], visited[MAXN][MAXN];

bool isSafe(int y, int x) {
    if ((y < 0) || (y >= n) || (x < 0) || (x >= n)) return false;
    return true;
}

int dijkstra() {
    priority_queue<ti, vector<ti>, greater<ti>> heap;
    heap.emplace(0, 0, 0);

    while (!heap.empty()) {
        auto [cost, y, x] = heap.top();
        heap.pop();

        if ((y == (n - 1)) && (x == (n - 1))) return cost;

        if (visited[y][x]) continue;
        visited[y][x] = true;

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            if (!isSafe(ny, nx)) continue;
            heap.emplace(cost + grid[ny][nx], ny, nx);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> grid[i][j];
    }

    cout << dijkstra() << "\n";
}