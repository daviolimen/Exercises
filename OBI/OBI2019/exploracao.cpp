#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 500001

ll n, p, q, bit[MAXN];
ll check[MAXN];
pair<ll, ll> points[MAXN];

ll compute(int i) {
    return (q * points[i].second - p * points[i].first);
}

void update(int k) {
    for (; k <= n; k += (k & -k)) {
        bit[k]++;
    }
}

ll query(int k) {
    ll res = 0;
    for (; k > 0; k -= (k & -k)) {
        res += bit[k];
    }
    return res;
}

ll solve() {
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        res += query(check[i]);
        update(check[i]);
    }
    return res;
}

int main() {
    cin >> n >> p >> q;
    if (q < 0) {
        q *= -1;
        p *= -1;
    }

    for (int i = 1; i <= n; i++) cin >> points[i].first >> points[i].second;

    sort(points + 1, points + n + 1);

    map<ll, int> mp;

    ll aux[MAXN];

    for (int i = 1; i <= n; i++) {
        check[i] = compute(i);
        aux[i] = check[i];
    }

    sort(aux + 1, aux + n + 1);

    for (int i = 1; i <= n; i++) {
        mp[aux[i]] = i;
    }

    for (int i = 1; i <= n; i++) check[i] = mp[check[i]];

    cout << solve() << "\n";
}