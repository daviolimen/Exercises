#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

int n, k, arr[MAXN];

bool bsearch(int x) {
    int ini = 0, fim = n - 1, meio;
    while (ini <= fim) {
        meio = (ini + fim) >> 1;
        if (arr[meio] == x) return true;
        else if (arr[meio] > x) {
            fim = meio - 1;
        } else {
            ini = meio + 1;
        }
    }
    return false;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];

    while (k--) {
        int x; cin >> x;
        cout << ((bsearch(x) ? "YES\n" : "NO\n"));
    }
}