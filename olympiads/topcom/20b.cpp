#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, -1, 1};

const int MAXL = 10;

int l, c, x, y, mat[MAXL][MAXL];


int main() {
    cin >> l >> c >> x >> y;
    mat[x][y] = 1;
    int cmd;
    while (true) {
        cin >> cmd;
        if (cmd == 0) break;
        x += dx[cmd];
        y += dy[cmd];
        if (x == -1) x = l - 1;
        if (x == l) x = 0;
        if (y == -1) y = c - 1;
        if (y == c) y = 0;
        mat[x][y] = 1;
    }

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}