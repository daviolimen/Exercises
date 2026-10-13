#include <bits/stdc++.h>
using namespace std;

#define MAXN 100100

int n, m, arr[MAXN];

int bsearch(int x) {
    int ini = 0, fim = n - 1, meio;
    while (ini <= fim) {
        meio = (ini + fim) / 2;

        if (arr[meio] == x) return meio;
        if (arr[meio] < x) ini = meio + 1;
        if (arr[meio] > x) fim = meio - 1;
    }
    return -1;
}

int main() {
    
}