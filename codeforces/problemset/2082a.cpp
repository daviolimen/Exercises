#include <bits/stdc++.h>
using namespace std;

char mat[100][100];

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }

        int badRows = 0, badCols = 0;

        for (int i = 0; i < n; i++) {
            int sumRow = 0;
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == '1') sumRow++;
            }
            if (sumRow % 2) badRows++;
        }
        
        for (int i = 0; i < m; i++) {
            int sumCol = 0;
            for (int j = 0; j < n; j++) {
                if (mat[j][i] == '1') sumCol++;
            }
            if (sumCol % 2) badCols++;
        }

        cout << max(badRows, badCols) << "\n";
    }
}