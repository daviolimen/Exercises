#include <bits/stdc++.h>
using namespace std;

int N, L, arr[60];

int bubble_sort(int ini, int fim) {
    int invs = 0;
    bool ord;
    while (true) {
        ord = true;
        for (int i = ini; i < fim; i++) {
            if (arr[i+1] < arr[i]) {
                invs++;
                ord = false;
                swap(arr[i], arr[i+1]);
            }
        }
        if (ord) break;
    }
    return invs;
}

int main() {
    scanf("%d", &N);
    for (int I = 0; I < N; I++) {
        scanf("%d", &L);
        for (int i = 0; i < L; i++) {
            scanf("%d", &arr[i]);
        }
        int ans = bubble_sort(0, L - 1);
        printf("Optimal train swapping takes %d swaps.\n", ans);
    }
}