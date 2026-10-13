#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1001;

int n, k, m, arr[MAXN], func[MAXN];
bool calc[MAXN];

int solve(int k) {
    if (calc[k]) return func[k];
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res += ((arr[i] % m) * (solve(k - i) % m)) % m;
        res %= m;
    }
    calc[k] = 1;
    return func[k] = res;
}

int32_t main() {
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) {
        cin >> func[i];
        calc[i] = 1;
    }
    cout << solve(k) << "\n";
}