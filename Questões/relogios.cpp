#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> ti;

#define MAXN 100

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

int n, m, k, pal[MAXN][MAXN];
bool visited[MAXN][MAXN];

bool isSafe(int y, int x) {
    if ((y < 0) || (y >= n) || (x < 0) || (x >= m)) return false;
    return true;
}

int dijkstra() {
    priority_queue<ti, vector<ti>, greater<ti>> heap;
    heap.emplace(0, 0, 0);

    while (!heap.empty()) {
        int t, y, x; tie(t, y, x) = heap.top();
        heap.pop();

        if (visited[y][x]) continue;
        visited[y][x] = true;

        if ((y == n - 1) && (x == m - 1)) {
            return t;
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            if (!isSafe(ny, nx)) continue;
            if (pal[ny][nx] == -1) {
                heap.emplace(t + 1, ny, nx);
            } else {
                if (pal[y][x] == -1) {
                    int espera = (pal[ny][nx] - 1) - (t % k);
                    if (espera < 0) espera += k;
                    heap.emplace(t + espera + 1, ny, nx);
                } else {
                    if (pal[ny][nx] == ((pal[y][x] + 1) % k)) {
                        heap.emplace(t + 1, ny, nx);
                    } else {
                        continue;
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> pal[i][j];
        }
    }

    cout << dijkstra() << "\n";
}