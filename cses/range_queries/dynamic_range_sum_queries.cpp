#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 200001

int n, q, arr[MAXN];
ll bit[MAXN];

void update(int k, int u) {
    int x = u - arr[k];
    arr[k] = u;
    for (; k <= n; k += (k & -k)) {
        bit[k] += x;
    }
}

ll soma(int k) {
    ll s = 0;
    for (; k > 0; k -= (k & -k)) {
        s += bit[k];
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false); ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        update(i, a);
    }

    while (q--) {
        int a, b, c; cin >> a >> b >> c;
        if (a == 1) {
            update(b, c);
        } else if (a == 2) {
            cout << (soma(c) - soma(b - 1)) << "\n";
        }
    }
}