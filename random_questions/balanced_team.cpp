#include <bits/stdc++.h>
using namespace std;

#define MAXN 200000

int n, arr[MAXN];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);

    int j = 0, best = 0;
    for (int i = 0; i < n; i++) {
        while ((j + 1 < n) && (arr[j + 1] - arr[i] <= 5)) {
            ++j;
        }
        best = max(best, j - i + 1);
    }
    cout << best << "\n";
}