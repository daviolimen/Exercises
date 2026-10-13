#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y;
    scanf("%d", &n);
    pair<int, int> arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x, &y);
        arr[i].first = y;
        arr[i].second = x;
    }
    sort(arr, arr + n);
    int ans = 1;
    int termino = arr[0].first;
    for (int i = 1; i < n; i++) {
        if (arr[i].second >= termino) {
            termino = arr[i].first;
            ans++;
        }
    }
    printf("%d\n", ans);
}