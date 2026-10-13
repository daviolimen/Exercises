#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000001

const int mod = 1e9 + 7;
int n, sums[MAXN];

int main() {
    cin >> n;
    sums[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i - j >= 0) {
                sums[i] += sums[i - j];
                sums[i] %= mod;
            }
        }
    }
    cout << sums[n] << "\n";
}