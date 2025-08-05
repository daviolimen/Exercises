#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n; cin >> n;
    if ((n < 1) || (n > 20)) {
        cout << "INVALIDO";
        return 0;
    }
    long long ans = 1;
    for (long long i = 2; i <= n; i++) ans *= i;
    cout << ans;
}