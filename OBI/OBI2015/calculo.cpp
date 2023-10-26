#include <bits/stdc++.h>
using namespace std;

#define MAXN 10010

int m, n, x[MAXN], y[MAXN], ans[MAXN];

int main() {
    cin >> m >> n;
    for (int i = 0; i < m; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> y[i];

    int s = max(m, n), fim = -1;

    for (int i = s - 1; i >= 0; i--) {
        ans[i] += x[i] + y[i];
        if (ans[i] >= 2) {
            ans[i] -= 2;
            ans[i - 1]++;
        }
        if (ans[i] != 0 && fim == -1) fim = i;
    }

    for (int i = 0; i <= fim; i++) cout << ans[i] << " \n"[i == fim];
}