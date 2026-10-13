#include <bits/stdc++.h>
using namespace std;

#define MAXN 1010

struct rena {
    char s[101];
    int p, i;
    float a;
};

int T, N, M;
rena arr[MAXN];

bool cmp(rena a, rena b) {
    if (a.p == b.p) {
        if (a.i == b.i) {
            if (a.a == b.a) {
                return (strcmp(a.s, b.s) < 0);
            } else {
                return a.a < b.a;
            }
        } else {
            return a.i < b.i;
        }
    } else {
        return a.p > b.p;
    }
}

int main() {
    scanf(" %d ", &T);
    for (int I = 1; I <= T; I++) {
        scanf(" %d %d ", &N, &M);
        for (int i = 0; i < N; i++) {
            scanf(" %s %d %d %f", arr[i].s, &arr[i].p, &arr[i].i, &arr[i].a);
        }
        sort(arr, arr + N, cmp);
        printf("CENARIO {%d}\n", I);
        for (int i = 0; i < M; i++) {
            printf("%d - %s\n", i+1, arr[i].s);
        }
    }
}
