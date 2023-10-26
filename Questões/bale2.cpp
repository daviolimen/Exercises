#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001

int n, bit[MAXN];

void update(int k) {
    for (; k <= n; k += (k & -k)) {
        bit[k]++;
    }
}

int query(int k) {
    int res = 0;
    for (; k > 0; k -= (k & -k)) {
        res += bit[k];
    }
    return res;
}

int main() {
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        ans += (query(n) - query(a));
        update(a);
    }

    cout << ans << "\n";
}