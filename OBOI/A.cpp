#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

int n, arr[MAXN];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);

    int best = INT_MAX;

    for (int i = 1; i < n; i++) {
        best = min(best, arr[i] - arr[i - 1]);
    }

    cout << best << "\n";
}