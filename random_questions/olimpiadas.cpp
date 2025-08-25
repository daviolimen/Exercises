#include <bits/stdc++.h>
using namespace std;

#define MAXN 110

struct pais {
    int ouro = 0, prata = 0, bronze = 0, id;
};

pais arr[MAXN];

bool cmp(pais a, pais b) {
    if (a.ouro == b.ouro) {
        if (a.prata == b.prata) {
            if (a.bronze == b.bronze) {
                return a.id < b.id;
            } else {
                return a.bronze > b.bronze;
            }
        } else {
            return a.prata > b.prata;
        }
    } else {
        return a.ouro > b.ouro;
    }
}

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++) {
        arr[i].id = i;
    }
    for (int i = 0; i < M; i++) {
        int o, p, b;
        scanf("%d%d%d", &o, &p, &b);
        arr[o].ouro++;
        arr[p].prata++;
        arr[b].bronze++;
    }
    sort(arr+1, arr+N+1, cmp);
    for (int i = 1; i <= N; i++) {
        printf("%d", arr[i].id);
        printf("%c", " \n"[i==N]);
    }
}