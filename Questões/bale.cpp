#include <bits/stdc++.h>
using namespace std;

#define MAXN 100100

typedef long long int lli;

int n, arr[MAXN], aux[MAXN];

lli merge_sort(int ini, int fim) {
    if (ini == fim) return 0;

    lli invs = merge_sort(ini, (ini + fim) / 2) + merge_sort((ini + fim) / 2 + 1, fim);
    int tam = 0;
    int j = (ini + fim) / 2 + 1;


    for (int i = ini; i <= ((ini + fim) / 2); i++) {
        while ((j <= fim) && (arr[j] < arr[i])) {
            aux[tam] = arr[j];
            tam++;
            j++;
            invs += (ini + fim) / 2 + 1 - i;
        }
        aux[tam] = arr[i];
        tam++;
    }

    while (j <= fim) {
        aux[tam] = arr[j];
        tam++;
        j++;
    }

    for (int i = ini; i <= fim; i++) arr[i] = aux[i - ini];

    return invs;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    lli ans = merge_sort(0, n - 1);
    printf("%lld\n", ans);
}