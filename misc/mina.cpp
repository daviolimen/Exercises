#include <bits/stdc++.h>
using namespace std;

#define MAXN 100

typedef tuple<int, int, int> ti;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

int n, mina[MAXN][MAXN];
bool visited[MAXN][MAXN];

bool isSafe(int y, int x) {
    if ((y < 0) || (y >= n) || (x < 0) || (x >= n)) return false;
    return true;
}

int dijkstra() {
    priority_queue<ti, vector<ti>, greater<ti>> heap;
    heap.emplace(0, 0, 0);

    while (!heap.empty()) {
        int c, y, x; tie(c, y, x) = heap.top();
        heap.pop();

        if (visited[y][x]) continue;
        visited[y][x] = true;

        if ((y == n - 1) && (x == n - 1)) return c;

        for (int i = 0; i < 4; i++) {
            int y2 = y + dy[i], x2 = x + dx[i];
            if (!isSafe(y2, x2)) continue;
            if (visited[y2][x2]) continue;
            heap.emplace(mina[y2][x2] + c, y2, x2);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mina[i][j];
        }
    }
    cout << dijkstra() << "\n";

}