#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001

int n, arr[MAXN], bit[MAXN];

void update(int x) {
    for (; x <= n; x += (x & -x)) {
        bit[x]++;
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
    ios::sync_with_stdio(false); ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    while (n != 0) {
        memset(arr, 0, sizeof(arr));
        memset(bit, 0, sizeof(bit));

        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }

        int invs = 0;
        for (int i = n; i > 0; i--) {
            update(arr[i]);
            invs += (query(arr[i] - 1) % 2);
            invs %= 2;
        }

        if (invs == 0) cout << "Carlos\n";
        else cout << "Marcelo\n";

        cin >> n;
    }
}