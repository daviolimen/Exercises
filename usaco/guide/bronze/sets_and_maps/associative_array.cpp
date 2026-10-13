#include <bits/stdc++.h>
using namespace std;

int q;
unordered_map<long long, long long> mp;

int main() {
    cin >> q;
    for (int i = 0; i < q; i++) {
        int op; cin >> op;
        if (op == 0) {
            long long k, v; cin >> k >> v;
            mp[k] = v;
        } else if (op == 1) {
            long long k; cin >> k;
            cout << mp[k] << "\n";
        }
    }
}