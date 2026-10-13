#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int ans = 0;
    while (n > 0) {
        ans++;
        int cpy = n, mx = 0;
        while (cpy > 0) {
            int c = cpy % 10;
            cpy /= 10;
            mx = max(mx, c);
        }
        n -= mx;
    }
    cout << ans << "\n";
}