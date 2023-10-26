#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;
ll arr[200100];

bool check(ll s) {
    int ctr = 1;
    ll soma = 0;
    for (int i = 1; i <= n; i++) {
        if (soma + arr[i] <= s) {
            soma += arr[i];
        } else if (arr[i] > s) {
            return false;
        } else {
            soma = arr[i];
            ctr++;
        }
    }
    return ctr <= k;
}

ll bsearch(ll fim) {
    ll ini = 1, meio, ans;
    while (ini <= fim) {
        meio = (ini + fim) / 2;
        if (check(meio)) {
            ans = meio;
            fim = meio - 1;
        } else {
            ini = meio + 1;
        }
    }
    return ans;
}

int main() {
    ll a, soma = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        soma += a;
        arr[i] = a;
    }
    cout << bsearch(soma) << "\n";
}