    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
        int tt; cin >> tt;
        while (tt--) {
            int n; cin >> n;
            string s; cin >> s;
            s = "0" + s;
            int ans = n;
            int changes = 0;
            for (int i = 1; i < s.size(); i++) {
                if (s[i] != s[i - 1]) {
                    ans++;
                    changes++;
                }
            }

            if (changes >= 3) ans -= 2;
            else if (changes >= 2) ans--;
            cout << ans << "\n";
        }
    }