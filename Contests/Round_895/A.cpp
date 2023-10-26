#include <bits/stdc++.h>
using namespace std;

int main() {
    int tt; cin >> tt;
    while (tt--) {
        int a, b, c; cin >> a >> b >> c;
        if (b > a) swap(a, b);
        int ans = ceil((float) (a - b) / (2 * c));
        cout << ans << "\n";
    }
}