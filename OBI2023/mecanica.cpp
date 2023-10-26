#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

int n, m, tempo[MAXN], fator[MAXN], curr[MAXN];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> tempo[i];
    for (int i = 0; i < m; i++) cin >> fator[i];

    sort(tempo, tempo + n);
    sort(fator, fator + m);

    long long ans = 0;

    for (int i = 0; i < n; i++) {
        ans += curr[i % m];
        curr[i % m] += tempo[i] * fator[i % m];
    }

    cout << ans << "\n";
}