#include <bits/stdc++.h>
using namespace std;

int main() {
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        for (int i = 1; i < n; i++) {
            int a, b; cin >> a >> b;
        }

        vector<int> f(n + 1);
        for (int i = 1; i <= n; i++) {
            cout << "? 1 1 " << i << "\n";
            cout.flush();
            cin >> f[i];
        }

        if (f[1] % 2) {
            cout << "! " << f[1];
            for (int i = 2; i <= n; i++) {
                cout << " " << f[i] - f[1];
            }
            cout << "\n";
            cout.flush();
            continue;
        }

        cout << "? 2 1\n";
        cout.flush();

        int l = 1, r = n;
        while (l < r) {
            int m = (l + r) / 2;
            int originalVal = 0, sz = m - l + 1;
            cout << "? 1 " << sz;
            for (int i = l; i <= m; i++) {
                originalVal += f[i];
                cout << " " << i;
            }
            cout << "\n";
            cout.flush();
            int newVal; cin >> newVal;
            if (abs(newVal - originalVal) == 2 * sz) l = m + 1;
            else r = m;
        }

        cout << "!";
        for (int i = 1; i <= n; i++) {
            cout << " ";
            if (i == 1) cout << ((f[1] - f[l] == 1) ? -1 : 1);
            else if (i == l) cout << f[i];
            else cout << f[i] - f[1];
        }
        cout << "\n";
        cout.flush();
    }
}