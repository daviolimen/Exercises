#include <bits/stdc++.h>
using namespace std;

#define MAXN 100100

int N, Q, q, arr[MAXN];

int binary_search(long long x) {
    int ini = 0, fim = N - 1, mid;
    while (ini <= fim) {
        mid = (ini + fim) / 2;
        if (arr[mid] == x) {
            int i = mid;
            while (arr[i - 1] == x) {
                i--;
            }
            return i;
        } else if (arr[mid] < x) {
            ini = mid + 1;
        } else {
            fim = mid - 1;
        }
    }
    return -1;
}

int main() {
    scanf("%d %d", &N, &Q);
    for (int i = 0; i < N; i++) cin >> arr[i];
    for (int i = 0; i < Q; i++) {
        scanf("%d", &q);
        printf("%d\n", binary_search(q));
    }
    return 0;
}