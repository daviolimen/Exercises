#include <bits/stdc++.h>
using namespace std;

#define MAXN 100

int n, x, arr[MAXN];

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);

    int ctr = 0, cost = 0;

    for (int i = 0; i < n; i++) {
        if (cost + arr[i] <= x) {
            cost += arr[i];
            ctr++;
        } else {
            break;
        }
    }

    cout << ctr << "\n";
}