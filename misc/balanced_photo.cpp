#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001

int n, h[MAXN], bit[MAXN];

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
    freopen("bphoto.in", "r", stdin);
    freopen("bphoto.out", "w", stdout);
    cin >> n;
    int temp[MAXN];
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        temp[i] = h[i];
    }

    sort(temp + 1, temp + n + 1);
    unordered_map<int, int> mp;
    for (int i = 1; i <= n; i++) mp[temp[i]] = i;

    for (int i = 1; i <= n; i++) {
        h[i] = mp[h[i]];
    }

    int l[MAXN], r[MAXN];

    for (int i = 1; i <= n; i++) {
        l[i] = query(n) - query(h[i]);
        update(h[i]);
    }

    memset(bit, 0, sizeof(bit));

    for (int i = n; i > 0; i--) {
        r[i] = query(n) - query(h[i]);
        update(h[i]);
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if (max(r[i], l[i]) > 2 * min(r[i], l[i])) ans++;
    }

    cout << ans << "\n";
}