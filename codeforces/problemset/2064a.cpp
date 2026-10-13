#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        string s; cin >> s;
        int ans = 0;
        if (s[0] == '1') ans++;
        for (int i = 1; i < n; i++) if (s[i] != s[i - 1]) ans++;
        cout << ans << "\n";
    }
}