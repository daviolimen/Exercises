#include <bits/stdc++.h>
using namespace std;

#define MAXN 200000

int n, k, arr[MAXN];

bool check(int x) {
    long long cost = 0;
    for (int i = n >> 1; i < n; i++) {
        if (arr[i] < x) cost += x - arr[i];
    }
    return cost <= k;
}

int bsearch() {
    int ini = 1, fim = (int) 2e9 + 10, meio, ans = -1;
    while (ini <= fim) {
        meio = (fim - ((fim - ini) >> 1));
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
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);

    cout << bsearch() << "\n";
}