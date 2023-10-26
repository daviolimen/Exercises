#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
#define MAXLOG 30

int n, arr[MAXN][2];

long long sum(int v, int q) {
    long long res = 0;
    for (int i = 0; i < n; i++) res += abs(arr[i][q] - v);
    return res;
}

int bsearch(int q) {
    int ini = 1, fim = (int) 1e9, meio;
    while (ini <= fim) {
        meio = (ini + fim) / 2;
        if (sum(meio + 1, q) <= sum(meio, q)) {
            ini = meio + 1;
        } else if (sum(meio - 1, q) < sum(meio, q)) {
            fim = meio - 1;
        } else break;
    }
    return meio;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i][0] >> arr[i][1];

    cout << bsearch(0) << " " << bsearch(1) << "\n";
}