#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000

int n, m;
char grid[MAXN][MAXN], mov[MAXN][MAXN];

bool isSafe(int y, int x) {
    if ((y < 0) || (y >= n) || (x < 0) || (x >= m)) return false;
    return true;
}



int main() {
    cin >> n >> m;
    int y0, x0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                y0 = i;
                x0 = j;
            }
        }
    }


}