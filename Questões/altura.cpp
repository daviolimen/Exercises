#include <bits/stdc++.h>
using namespace std;

int main() {
    int nc, n, h;
    scanf("%d", &nc);
    for (int i = 0; i < nc; i++) {
        scanf("%d", &n);
        int *arr = new int[n];
        for (int j = 0; j < n; j++) {
            scanf("%d", &h);
            arr[j] = h;
        }
        sort(arr, arr + n);
        for (int j = 0; j < n - 1; j++) {
            printf("%d ", arr[j]);
        }
        printf("%d\n", arr[n - 1]);
    }
}