#include <bits/stdc++.h>
using namespace std;

const int DY[] = {-1, 0, 1, 0};
const int DX[] = {0, 1, 0, -1};

int n, m, s;
char grid[100][100], seq[50010];

bool notSafe(int y, int x) {
    if ((y < 0) || (y >= n) || (x < 0) || (x >= m) || (grid[y][x] == '#')) return 1;
    return 0;
}

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    while (true) {
        cin >> n >> m >> s;
        if (n == 0) break;
        int yi, xi, di;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
                if ((grid[i][j] == '.') || (grid[i][j] == '*') || (grid[i][j] == '#')) continue;
                yi = i;
                xi = j;
                if (grid[i][j] == 'N') di = 0;
                else if (grid[i][j] == 'L') di = 1;
                else if (grid[i][j] == 'S') di = 2;
                else di = 3;
            }
        }

        int ans = 0;
        for (int i = 0; i < s; i++) {
            if (grid[yi][xi] == '*') {
                grid[yi][xi] = '.';
                ans++;
            }
            char cur; cin >> cur;
            if (cur == 'D') {
                di = (di + 1) % 4;
            }
            if (cur == 'E') {
                di = (di + 3) % 4;
            }
            if (cur == 'F') {
                int ny = yi + DY[di];
                int nx = xi + DX[di];
                if (notSafe(ny, nx)) continue;
                yi = ny;
                xi = nx;
            }
        }
        if (grid[yi][xi] == '*') ans++;
        cout << ans << "\n";
    }
}