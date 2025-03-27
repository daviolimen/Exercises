#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        if (n % 2 == 0) {
            cout << "-1\n";
            continue;
        }
        vector<int> ans(n + 1);
        for (int i = 1; i <= n; i++) {
            ans[i] = (2 * i - 1) % n;
            if (ans[i] == 0) ans[i] = n;
        }
        for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
    }
}