#include <bits/stdc++.h>
using namespace std;

const int maxn = 500;

int n, f;
char mat[maxn][maxn];

bool isSafe(int y, int x) {
    if ((y < 0) || (y >= n) || (x < 0) || (x >= n)) return false;
    return true;
}

void solve(int y, int x) {
    if ((!isSafe(y, x)) || (mat[y][x] == '*') || (mat[y][x] - '0' > f)) return;
    mat[y][x] = '*';
    solve(y - 1, x);
    solve(y + 1, x);
    solve(y, x - 1);
    solve(y, x + 1);
}

int main() {
    cin >> n >> f;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    solve(0, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j];
        }
        cout << "\n";
    }
}