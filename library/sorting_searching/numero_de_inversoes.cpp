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
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    int invs = merge_sort(1, n);
    cout << invs << "\n";
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " \n"[i == n];
    }
}