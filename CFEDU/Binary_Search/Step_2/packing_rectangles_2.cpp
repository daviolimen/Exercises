#include <bits/stdc++.h>
using namespace std;

long long w, h, n;

bool check(long long x) {
    return (x / w) * (x / h) >= n;
}

int main() {
    cin >> w >> h >> n;

    long long ini = 0, fim = 1;
    while (!check(fim)) fim *= 2;

    while (fim > ini + 1) {
        long long meio = (ini + fim) >> 1;
        if (check(meio)) fim = meio;
        else ini = meio;
    }

    cout << fim << "\n";
}