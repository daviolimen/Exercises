#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    vector<int> fib(11);
    fib[1] = 1;
    fib[2] = 2;
    for (int i = 3; i < 11; i++) fib[i] = fib[i - 1] + fib[i - 2];
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        int c1 = fib[n], c2 = fib[n - 1];
        string ans;
        for (int i = 0; i < m; i++) {
            int med[3]; cin >> med[0] >> med[1] >> med[2];

            bool tst = false;
            for (int j = 0; j < 3; j++) {
                tst = tst || (c1 > med[j]);
            }

            if (tst) {
                ans.push_back('0');
                continue;
            }

            tst = false;
            for (int j = 0; j < 3; j++) {
                tst = tst || (c1 + c2 <= med[j]);
            }

            if (tst) {
                ans.push_back('1');
                continue;
            }

            ans.push_back('0');
        }

        cout << ans << "\n";
    }
}