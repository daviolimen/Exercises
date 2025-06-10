#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(n + 1);
        int soma1 = 0;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            soma1 += arr[i];
        }

        soma1 *= 2;
        if (soma1 % (n * (n + 1)) == 0) soma1 /= (n * (n + 1));
        else {
            cout << "NO\n";
            continue;
        }

        int eq1 = arr[1] - soma1;
        if (eq1 % (n - 1) == 0) eq1 /= (n - 1);
        else {
            cout << "NO\n";
            continue;
        }

        int sol2 = eq1;
        int sol1 = soma1 - sol2;

        if ((sol1 < 0) || (sol2 < 0)) {
            cout << "NO\n";
            continue;
        }

        bool ok = true;
        for (int i = 1; i <= n; i++) {
            int res = sol1 * i + sol2 * (n - i + 1);
            if (res == arr[i]) continue;
            ok = false;
            break;
        }

        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
}