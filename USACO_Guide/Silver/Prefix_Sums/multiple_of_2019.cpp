#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 200001;
const int MOD = 2019;

int n, suffix[MAXN], restos[MOD];
string arr;

int xpow(int x, int p) {
    int res = 1;
    while (p > 0) {
        if (p & 1) res = (res * x) % MOD;
        p >>= 1;
        x = (x * x) % MOD;
    }
    return res;
}

int main() {
    cin >> arr;
    n = arr.size();

    restos[0] = 1;
    for (int i = 1; i <= n; i++) {
        suffix[i] = (suffix[i - 1] + (arr[n - i] - '0') * xpow(10, i - 1)) % MOD;
        restos[suffix[i]]++;
    }

    ll ans = 0;
    for (int i = 0; i < MOD; i++) {
        ans += (ll) ((restos[i] * (restos[i] - 1)) / 2);
    }
    cout << ans << "\n";
}