#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 10001

int n, smallCases[] = {0, 0, 6, 28, 96, 252, 550, 1056, 1848};

ll count(ll k) {
    if (k <= 8) return smallCases[k];
    return ((k * k * k * k - 9 * k * k + 24 * k - 16) / 2);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << count(i) << "\n";
    }
}