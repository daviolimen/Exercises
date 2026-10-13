#include <bits/stdc++.h>
using namespace std;

const int MAXM = 200100;

int m;
bool grid[2][MAXM];

void solve() {
    cin >> m;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            grid[i][j] = (c == 'B');
        }
    }

    int start = -1;

    for (int i = 0; i < m; i++) {
        if (grid[0][i] && grid[1][i]) continue;
        start = i;
        break;
    }

    if (start == -1) {
        cout << "YES\n";
        return;
    }

    bool ans = true;

    int twoCtr = 0;

    for (int i = start + 1; i < m; i++) {
        if ((grid[0][i - 1] != grid[0][i]) && (grid[1][i - 1] != grid[1][i])) ans = false;
        if (grid[0][i] && grid[1][i]) twoCtr++;
        else if (twoCtr > 0) {
            if (twoCtr % 2) {
                if ((grid[0][i] && grid[0][i - twoCtr - 1]) || (grid[1][i] && grid[1][i - twoCtr - 1])) {
                    ans = false;
                }
            } else {
                if ((grid[0][i] && grid[1][i - twoCtr - 1]) || (grid[1][i] && grid[0][i - twoCtr - 1])) {
                    ans = false;
                }
            }
            twoCtr = 0;
        }
    }

    for (int i = start - 1; i >= 0; i--) {
        if ((grid[0][i] != grid[0][i + 1]) && (grid[1][i + 1] != grid[1][i])) ans = false;
        if (grid[0][i] && grid[1][i]) twoCtr++;
        else if (twoCtr > 0) {
            if (twoCtr % 2) {
                if ((grid[0][i] && grid[0][i + twoCtr + 1]) || (grid[1][i] && grid[1][i + twoCtr + 1])) {
                    ans = false;
                }
            } else {
                if ((grid[0][i] && grid[1][i + twoCtr + 1]) || (grid[1][i] && grid[0][i + twoCtr + 1])) {
                    ans = false;
                }
            }
            twoCtr = 0;
        }
    }

    cout << ((ans) ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
}