#include <bits/stdc++.h>
using namespace std;

#define MAXN 200000

int n, coins[MAXN];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    sort(coins, coins + n);

    long long res = 1;

    for (int i = 0; i < n; i++) {
        if (coins[i] > res) {
            break;
        }
        res += coins[i];
    }

    cout << res << "\n";
}