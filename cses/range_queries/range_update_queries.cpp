#include <bits/stdc++.h>
using namespace std;

#define MAXN 200010

int n, q, arr[MAXN], diff[MAXN];
long long bit[MAXN];

void update(int k, int x) {
    for (; k <= n; k += (k & -k)) {
        bit[k] += x;
    }
}

long long query(int k) {
    long long res = 0;
    for (; k > 0; k -= (k & -k)) {
        res += bit[k];
    }
    return res;
}

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        update(i, arr[i] - arr[i - 1]);
    }

    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int a, b, u; cin >> a >> b >> u;
            update(a, u);
            update(b + 1, -u);
        } else if (op == 2) {
            int k; cin >> k;
            cout << query(k) << "\n";
        }
    }
}