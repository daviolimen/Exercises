#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXK 45

int n, k, primos[MAXK], soma;

void incExc(int i, ll mult, int qnt) {
    if (mult > n) return;

    if (i == k) {
        if (mult == 1 || qnt == 0) return;
        if (qnt % 2) soma += (n / mult);
        else soma -= (n / mult);
        return;
    }

    incExc(i + 1, mult, qnt);
    incExc(i + 1, mult * primos[i], qnt + 1);
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < k; i++) cin >> primos[i];

    incExc(0, 1, 0);

    cout << (n - soma) << "\n";
}