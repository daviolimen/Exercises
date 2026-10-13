#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001

int n, k, arr[MAXN];

int bsearch(int x) {
    int ini = 1, fim = n, meio, ans = n + 1;
    while (ini <= fim) {
        meio = (ini + fim) >> 1;
        if (arr[meio] >= x) {
            ans = meio;
            fim = meio - 1;
        } else {
            ini = meio + 1;
        }
    }
    return ans;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    while (k--) {
        int x; cin >> x;
        cout << bsearch(x) << "\n";
    }
}