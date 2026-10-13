#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e7;

int main() {
    ios::sync_with_stdio(0); ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);

    bitset<MAXN + 1> crivo;
    crivo[1] = 1;
    for (int i = 2; i <= MAXN; i++) {
        for (int j = 2 * i; j <= MAXN; j += i) {
            crivo[j] = 1;
        }
    }

    vector<int> primos(MAXN + 1);
    for (int i = 1; i <= MAXN; i++) primos[i] = primos[i - 1] + (!crivo[i]);

    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        int ans = 0;
        for (int a = 1; a < n; a++) {
            ans += primos[n / a];
        }
        cout << ans << "\n";
    }
}