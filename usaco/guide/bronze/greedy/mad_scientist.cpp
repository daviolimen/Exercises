#include <bits/stdc++.h>
using namespace std;

int n;
string a, b;

int main() {
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);

    cin >> n >> a >> b;

    int ans = 0;
    bool flipping = false;

    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            if (flipping) continue;
            flipping = true;
        } else {
            if (!flipping) continue;
            flipping = false;
            ans++;
        }
    }

    if (flipping) ans++;

    cout << ans << "\n";
}