#include <bits/stdc++.h>
using namespace std;

const int dy[] = {0, -1, -1};
const int dx[] = {-1, 0, -1};

const int MAXN = 101;

int n, mat[MAXN][MAXN];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> mat[i][j];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            int ctr = 0;
            for (int k = 0; k < 3; k++) {
                if (mat[i + dy[k]][j + dx[k]] == 0) ctr++;
            }
            if (ctr >= 2) mat[i][j] = 1;
            else mat[i][j] = 0;
        }
    }
    cout << mat[n - 1][n - 1] << "\n";
}