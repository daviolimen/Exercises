#include <bits/stdc++.h>
using namespace std;

int ans = 0;
char grid[8][8];
bool column[8], diag1[15], diag2[15];

void search(int y) {
    if (y == 8) {
        ans++;
        return;
    }
    for (int x = 0; x < 8; x++) {
        if (column[x] || diag1[x + y] || diag2[x - y + 7] || grid[y][x] == '*') continue;
        column[x] = diag1[x + y] = diag2[x - y + 7] = 1;
        search(y + 1);
        column[x] = diag1[x + y] = diag2[x - y + 7] = 0;
    }
}

int main() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> grid[i][j];
        }
    }
    search(0);
    cout << ans << "\n";
}