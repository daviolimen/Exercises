#include <bits/stdc++.h>
using namespace std;

#define MAXN 25

int N, transf[MAXN][2]; // {destino, origem}

void construct() {
    sort(transf + 1, transf + 1 + N);
}

int main() {
    scanf("%d", &N);
    while (N != 0) {
        for (int i = 1; i <= N; i++) {
            transf[i][1] = i;
            scanf("%d", &transf[i][0]);
        }

        scanf("%d", &N);
    }
}