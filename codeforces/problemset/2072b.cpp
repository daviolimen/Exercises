#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        string s; cin >> s;
        int hyfen = 0, under = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '-') hyfen++;
            if (s[i] == '_') under++;
        }

        int ans = (hyfen / 2) * under * (hyfen - (hyfen / 2));
        cout << ans << "\n";
    }
}