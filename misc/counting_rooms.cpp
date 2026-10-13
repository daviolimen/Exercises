#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, m;
char grid[MAXN][MAXN + 1];
char obstacle = 'X';

bool isSafe(int y, int x) {
    if ((y < 0) || (y >= n) || (x < 0) || (x >= m)) return false;
    return true;
}

void floodFill(int y, int x) {
    if (!isSafe(y, x)) return;
    if (grid[y][x] == '.') grid[y][x] = obstacle;
    else return;
    for (int i = 0; i < 4; i++) floodFill(y+dy[i], x+dx[i]);
}

int main() {
    scanf("%d%d", &n, &m);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        scanf("%s", grid[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                ans++;
                floodFill(i, j);
            }
        }
    }
    printf("%d\n", ans);
}