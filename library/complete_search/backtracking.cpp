#include <bits/stdc++.h>
using namespace std;

#define MAXN 20

int n, ans = 0;
bool column[MAXN], diag1[2 * MAXN], diag2[2 * MAXN];

void search(int y) {
    if (y == n) {
        ans++;
        return;
    }
    for (int x = 0; x < n; x++) {
        if (column[x] || diag1[x + y] || diag2[x - y + n - 1]) continue;
        column[x] = diag1[x + y] = diag2[x - y + n - 1] = 1;
        search(y + 1);
        column[x] = diag1[x + y] = diag2[x - y + n - 1] = 0;
    }
}

int main() {
    cin >> n;
    search(0);
    cout << ans << "\n";
}