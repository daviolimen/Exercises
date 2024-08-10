#include <bits/stdc++.h>
using namespace std;

const int dk1[] = {1, 1, -1, -1};
const int dk2[] = {1, -1, 1, -1};

const int MAXN = 100;

int n, k, pistas[MAXN][MAXN], pos[MAXN][MAXN];

bool notSafe(int x, int y) {
    if ((x < 0) || (x >= n) || (y < 0) || (y >= n)) return 1;
    return 0;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int a, b, c; cin >> a >> b >> c;
        if (!notSafe(a, b + c)) pos[a][b + c]++;
        if (!notSafe(a, b - c)) pos[a][b - c]++;
        if (!notSafe(a + c, b)) pos[a + c][b]++;
        if (!notSafe(a - c, b)) pos[a - c][b]++;
        for (int j = 1; j < c; j++) {
            for (int k = 0; k < 4; k++) {
                int nx = a + dk1[k] * j;
                int ny = b + dk2[k] * (c - j);
                if (notSafe(nx, ny)) continue;
                pos[nx][ny]++;
            }
        }
    }

    int num = 0, xa, ya;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (pos[i][j] == k) num++, xa = i, ya = j;
        }
    }

    if (num > 1) cout << "-1 -1\n";
    else cout << xa << " " << ya << "\n";
}