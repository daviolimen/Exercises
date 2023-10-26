#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001

int n, q, arr[MAXN], bit[MAXN];

void update(int k, int p) {
    int c = p - arr[k];
    arr[k] = p;
    for (; k <= n; k += (k & -k)) {
        bit[k] += c;
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
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        update(i, a);
    }

    while (q--) {
        int op; cin >> op;
        if (op == 0) {
            int k, p; cin >> k >> p;
            update(k, p);
        } else if (op == 1) {
            int k; cin >> k;
            cout << query(k) << "\n";
        }
    }
}