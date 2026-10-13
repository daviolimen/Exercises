#include <bits/stdc++.h>
using namespace std;

const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

#define MAXN 1000

int n, area, peri;
char grid[MAXN][MAXN];
bool visited[MAXN][MAXN];

bool notSafe(int y, int x) {
    if ((y < 0) || (y >= n) || (x < 0) || (x >= n)) return true;
    return false;
}

void floodFill(int y, int x) {
    if ((notSafe(y, x)) || (visited[y][x]) || (grid[y][x] == '.')) return;
    visited[y][x] = true;
    area++;
    for (int i = 0; i < 4; i++) {
        if ((notSafe(y + dy[i], x + dx[i])) || (grid[y + dy[i]][x + dx[i]] == '.')) peri++;
        floodFill(y + dy[i], x + dx[i]);
    }
}

int main() {
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int bestA = 0, bestPeri = INT_MAX;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((grid[i][j] == '.') || (visited[i][j])) continue;
            area = 0, peri = 0;
            floodFill(i, j);
            if (area > bestA) {
                bestA = area;
                bestPeri = peri;
            } else if (area == bestA) {
                bestPeri = min(bestPeri, peri);
            }
        }
    }

    cout << bestA << " " << bestPeri << "\n";
}