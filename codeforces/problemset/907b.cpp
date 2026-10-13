#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<char>> grid(9, vector<char>(9));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> grid[i][j];
        }
    }

    int y, x; cin >> y >> x;
    y--, x--;
    int tabY = y % 3;
    int tabX = x % 3;

    bool hasEmpty = 0;

    for (int i = tabY * 3; i < tabY * 3 + 3; i++) {
        for (int j = tabX * 3; j < tabX * 3 + 3; j++) {
            if (grid[i][j] == '.') {
                hasEmpty = 1;
                grid[i][j] = '!';
            }
        }
    }

    if (!hasEmpty) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (grid[i][j] == '.') grid[i][j] = '!';
            }
        }
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << grid[i][j];
            if (j % 3 == 2) cout << " \n"[j == 8];
        }
        if ((i != 8) && (i % 3 == 2)) cout << "\n";
    }
}