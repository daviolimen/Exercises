#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000

int n;
char grid[MAXN][MAXN];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        int first = -1, last = -1, ctr = 0;
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '*') {
                if (first == -1) first = j;
                last = j;
                ctr++;
            }
        }

        if ((first != -1) && (ctr != (last - first + 1))) {
            cout << "N\n";
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        int first = -1, last = -1, ctr = 0;
        for (int j = 0; j < n; j++) {
            if (grid[j][i] == '*') {
                if (first == -1) first = j;
                last = j;
                ctr++;
            }
        }

        if ((first != -1) && (ctr != (last - first + 1))) {
            cout << "N\n";
            return 0;
        }
    }

    cout << "S\n";
    return 0;
}