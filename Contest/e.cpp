#include <bits/stdc++.h>
using namespace std;

int n, q, perm[200100];

int runQuery(int l, int r, int k) {
    
}

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        cin >> n >> q;
        for (int i = 0; i < n; i++) cin >> perm[i];
        while (q--) {
            int l, r, x; cin >> l >> r >> x;
            cout << runQuery(l, r, x) << " \n"[!q];
        }
    }
}