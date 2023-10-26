#include <bits/stdc++.h>
using namespace std;

#define MAXN 101

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

int N, M, K, tamanhos[MAXN * MAXN], grid_i[MAXN][MAXN];
char grid[MAXN][MAXN];

bool isSafe(int y, int x) {
    if ((y < 0) || (y >= N) || (x < 0) || (x >= M)) return false;
    return true;
}

void flood_fill(int y, int x, int c) {
    if (!isSafe(y, x)) return;
    if (grid[y][x] == '.') return;
    grid[y][x] = '.';
    grid_i[y][x] = c;
    tamanhos[c]++;
    for (int i = 0; i < 4; i++) flood_fill(y + dy[i], x + dx[i], c);
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%s", grid[i]);
    }

    for (int i = 0; i < N; i++) {
        fill(grid_i[i], grid_i[i] + M, -1);
    }

    int nome = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == '#') flood_fill(i, j, nome++);
        }
    }

    int ans = 0;
    scanf("%d", &K);
    int L, C;
    for (int i = 0; i < K; i++) {
        scanf("%d%d", &L, &C);
        L--; C--;
        if (grid_i[L][C] == -1) continue;
        tamanhos[grid_i[L][C]]--;
        if (tamanhos[grid_i[L][C]] == 0) ans++;
        grid_i[L][C] = -1;
    }
    cout << ans << "\n";
}