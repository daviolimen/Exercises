#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500001, MAXR = 1000001;

int n, ctr[MAXR], prefix[MAXR];

bool check(int k) {
    if ((prefix[1000000] - prefix[k - 1]) >= k) return true;
    return false;
}

int bsearch() {
    int ini = 1, fim = 1000000, meio, ans = 0;
    while (ini <= fim) {
        meio = (ini + fim) >> 1;
        if (check(meio)) {
            ans = meio;
            ini = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return ans;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        ctr[a]++;
    }

    for (int i = 1; i < MAXR; i++) {
        prefix[i] = prefix[i - 1] + ctr[i];
    }

    cout << bsearch() << "\n";
}