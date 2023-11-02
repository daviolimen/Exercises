#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001

int n, arr[MAXN];

int ubound(int x) {
    int ini = 1, fim = n, meio, ans = n + 1;
    while (ini <= fim) {
        meio = (ini + fim) >> 1;
        if (arr[meio] > x) {
            ans = meio;
            fim = meio - 1;
        } else {
            ini = meio + 1;
        }
    }

    return ans;
}

int lbound(int x) {
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
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    sort(arr + 1, arr + n + 1);
    
    int k; cin >> k;
    while (k--) {
        int l, r; cin >> l >> r;
        cout << ubound(r) - lbound(l) << "\n";
    }
}