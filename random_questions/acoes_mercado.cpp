#include <bits/stdc++.h>
using namespace std;

int ans(int n, int k) {
    if (n <= k) {
        return 1;
    } else {
        if ((n % 2) == 0) {
            return 2 * ans(n / 2, k);
        } else {
            return (ans((n + 1) / 2, k) + ans((n - 1) / 2, k));
        }
    }
}

int main() {
    int N, K;
    scanf("%d%d", &N, &K);
    while (N != 0) {
        printf("%d\n", ans(N, K));
        scanf("%d%d", &N, &K);
    }
}