/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: castle
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

const int DY[] = {0, -1, 0, 1};
const int DX[] = {-1, 0, 1, 0};
const char DIR[] = {'W', 'N', 'E', 'S'};
const int MAXN = 50;

int n, m, ctr, grid[MAXN][MAXN];
bool visited[MAXN][MAXN];

bool notSafe(int y, int x) {
    if ((y < 0) || (y >= n) || (x < 0) || (y >= m)) return 1;
    return 0;
}

void floodFill(int y, int x) {
    if (notSafe(y, x)) return;
    if (visited[y][x]) return;
    ctr++;
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        if (grid[y][x] & (1 << i)) continue;
        floodFill(y + DY[i], x + DX[i]);
    }
}

int main() {
    ifstream cin ("castle.in");
    ofstream cout ("castle.out");
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int qntRoom = 0, bigRoom = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ctr = 0;
            if (visited[i][j]) continue;
            qntRoom++;
            floodFill(i, j);
            bigRoom = max(bigRoom, ctr);
        }
    }

    int bestRoom = 0, bestWall[2] = {-1, -1};
    char bestDir = 'x';

    for (int j = 0; j < m; j++) {
        for (int i = n - 1; i >= 0; i--) {
            for (int l = 1; l <= 4; l++) {
                int k = l % 4;
                if (i == 0 && k == 1) continue;
                if (i == n - 1 && k == 3) continue;
                if (j == 0 && k == 0) continue;
                if (j == m - 1 && k == 2) continue;
                if (!(grid[i][j] & (1 << k))) continue;
                memset(visited, 0, sizeof(visited));
                grid[i][j] &= ~(1 << k);
                ctr = 0;
                floodFill(i, j);
                if (ctr > bestRoom) {
                    bestRoom = ctr;
                    bestWall[0] = i;
                    bestWall[1] = j;
                    bestDir = DIR[k];
                }
                grid[i][j] |= (1 << k);
            }
        }
    }

    cout << qntRoom << "\n";
    cout << bigRoom << "\n";
    cout << bestRoom << "\n";
    cout << bestWall[0] + 1 << " " << bestWall[1] + 1 << " " << bestDir << "\n";
    return 0;
}