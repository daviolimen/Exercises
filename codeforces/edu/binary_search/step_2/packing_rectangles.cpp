#include <bits/stdc++.h>
using namespace std;

long long w, h, n;

bool check(long long x) {
    return (x / w) * (x / h) >= n;
}

int main() {
    cin >> w >> h >> n;

    long long ini = 1, fim = 1, ans;
    while (!check(fim)) fim *= 2;

    while (ini <= fim) {
        long long meio = (ini + fim) >> 1;
        if (check(meio)) {
            ans = meio;
            fim = meio - 1;
        } else {
            ini = meio + 1;
        }
    }

    cout << ans << "\n";
}