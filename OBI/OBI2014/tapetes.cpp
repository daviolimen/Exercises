#include <bits/stdc++.h>
using namespace std;

long long l, n;

int main() {
    cin >> l >> n;

    long long res = (l - n + 1) * (l - n + 1) + (n - 1);

    cout << res << "\n";
}