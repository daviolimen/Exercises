#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        string s; cin >> s;
        int n = s.size();
        int ans = 0;
        bool found = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0' && !found) ans++;
            if (s[i] != '0' && found) ans++;
            if (s[i] != '0' && !found) found = 1;
        }

        cout << ans << "\n";
    }
}