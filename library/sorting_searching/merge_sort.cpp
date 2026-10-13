#include <bits/stdc++.h>
using namespace std;

#define MAXN 100100

int n, arr[MAXN], aux[MAXN];

void merge_sort(int ini, int fim) {
    if (ini == fim) return;

    merge_sort(ini, (ini + fim) / 2);
    merge_sort((ini + fim) / 2 + 1, fim);

    int tam = 0, j = (ini + fim) / 2 + 1;

    for (int i = ini; i <= (ini + fim) / 2; i++) {
        while ((j <= fim) && (arr[j] < arr[i])) {
            aux[tam] = arr[j];
            tam++;
            j++;
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
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    merge_sort(0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}