#include <bits/stdc++.h>
using namespace std;

#define MAXN 20

int n;
bool pcl[MAXN][MAXN];
char grid[MAXN][MAXN];

bool checkRect(int y1, int x1, int y2, int x2) {
    
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = 0;

    for (int y1 = 0; y1 < n; y1++) {
        for (int x1 = 0; x1 < n; x1++) {
            for (int y2 = n - 1; y2 >= y1; y2--) {
                for (int x2 = n - 1; x2 >= x1; x2--) {
                    if ((pcl[y1][x1]) && (pcl[y2][x2])) continue; // maybe not??
                    if (checkRect(y1, x1, y2, x2)) ans++;
                }
            }
        }
    }

    cout << ans << "\n";
}