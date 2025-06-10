#include <bits/stdc++.h>
using namespace std;

int main() {
    int tt; cin >> tt;
    while (tt--) {
        int x; cin >> x;
        int cur = 0, cnt = 0;
        while (cur < x) {
            cur = 2 * cur + 1;
            cnt++;
        }
        int ans = 2 * cnt + 1;
        cout << ans << "\n";
    }
}