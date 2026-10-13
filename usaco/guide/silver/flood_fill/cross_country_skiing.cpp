#include <bits/stdc++.h>
using namespace std;

const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

#define MAXN 500

int n, m, sy, sx, grid[MAXN][MAXN];
bool waypoints[MAXN][MAXN], visited[MAXN][MAXN];

bool notSafe(int y, int x) {
    if ((y < 0) || (y >= n) || (x < 0) || (x >= m)) return true;
    return false;
}

void floodFill(int y, int x, int last, int D) {
    if ((notSafe(y, x)) || (visited[y][x]) || (abs(grid[y][x] - last) > D)) return;
    visited[y][x] = true;

    for (int i = 0; i < 4; i++) floodFill(y + dy[i], x + dx[i], grid[y][x], D);
}

bool check(int D) {
    memset(visited, 0, sizeof(visited));
    floodFill(sy, sx, grid[sy][sx], D);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((waypoints[i][j]) && (!visited[i][j])) return false;
        }
    }
    return true;
}

int bsearch() {
    int ini = -1, fim = 1000000000;
    while (fim - ini > 1) {
        int meio = (ini + fim) >> 1;
        if (check(meio)) fim = meio;
        else ini = meio;
    }
    return fim;
}

int main() {
    freopen("ccski.in", "r", stdin);
    freopen("ccski.out", "w", stdout);
    
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    sy = -1, sx = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> waypoints[i][j];
            if ((waypoints[i][j]) && (sy == -1) && (sx == -1)) sy = i, sx = j; 
        }
    }

    cout << bsearch() << "\n";
}