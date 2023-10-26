#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001

int n, dp[MAXN];
vector<int> filhos[MAXN];

int sub(int x) {
    if (dp[x] != -1) return dp[x];

    int res = 0;
    for (auto f : filhos[x]) {
        res += sub(f) + 1;
    }
    return dp[x] = res;
}

int main() {
    cin >> n;
    int p;
    for (int i = 2; i <= n; i++) {
        cin >> p;
        filhos[p].push_back(i);
    }

    memset(dp, -1, sizeof(dp));

    for (int i = 1; i <= n; i++) {
        cout << sub(i) << " \n"[i == n];
    }
}