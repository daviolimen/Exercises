#include <bits/stdc++.h>
using namespace std;

int main() {
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        string s; cin >> s;
        int ctr = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') ctr++;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += ctr;
            if (s[i] == '0') ans++;
            else ans--;
        }
        cout << ans << "\n";
    }
}