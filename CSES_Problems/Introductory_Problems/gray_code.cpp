#include <bits/stdc++.h>
using namespace std;

#define MAXN 17

int dp[MAXN][1 << MAXN], base[] = {0, 1};
bitset<MAXN> mark;

int* solve(int x) {
    if (x == 1) {
        return base;
    }

    if (mark[x]) return dp[x];

    mark[x] = 1;

    for (int i = (1 << (x - 1)); i < (1 << x); i++) {
        dp[x][i] = 1 << (x - 1);
    }

    auto aux = solve(x - 1);

    for (int i = 0; i < (1 << (x - 1)); i++) {
        dp[x][i] |= aux[i];
    }

    reverse(aux, aux + (1 << (x - 1)));

    for (int i = 0; i < (1 << (x - 1)); i++) {
        dp[x][i + (1 << (x - 1))] |= aux[i];
    }

    return dp[x];
}

int main() {
    int n;
    cin >> n;
    auto ans = solve(n);
    for (int i = 0; ((ans[i] != 0) || (!i)); i++) {
        for (int j = 0; j < n; j++) {
            if (ans[i] & (1 << j)) cout << 1;
            else cout << 0;
        }
        cout << "\n";
    }
}