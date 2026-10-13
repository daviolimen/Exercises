#include <bits/stdc++.h>
using namespace std;

int main() {
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for (auto &x : a) cin >> x;
        vector<bool> freq(n + 1);
        int ctr = 0;
        for (int i = 0; i < n; i++) {
            if (freq[a[i]]) continue;
            ctr++;
            freq[a[i]] = 1;
        }
        cout << ctr << "\n";
    }
}