#include <bits/stdc++.h>
using namespace std;

const int dy[] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};

const int MAXN = 52;

int n, q;
char mat[MAXN][MAXN];
bool change[MAXN][MAXN];

bool notSafe(int y, int x) {
    if ((y < 0) || (y >= n) || (x < 0) || (x >= n)) return true;
    return false;
}

int countNeighbors(int y, int x) {
    int ctr = 0;
    for (int i = 0; i < 8; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if (notSafe(ny, nx) || (mat[ny][nx] == '0')) continue;
        ctr++;
    }
    return ctr;
}

void solve() {
    memset(change, 0, sizeof(change));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int neigh = countNeighbors(i, j);
            if ((mat[i][j] == '0') && (neigh == 3)) change[i][j] = 1;
            if ((mat[i][j] == '1') && ((neigh < 2) || (neigh > 3))) change[i][j] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (change[i][j] == 1) mat[i][j] = ((mat[i][j] == '0') ? '1' : '0');
        }
    }
}

int main() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    for (int i = 0; i < q; i++) {
        solve();
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j];
        }
        cout << "\n";
    }
}