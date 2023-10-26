#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, arr[3];
    cin >> n >> arr[0] >> arr[1] >> arr[2];

    sort(arr, arr + 3);

    int ctr = 0;

    for (int i = 0; i < 3; i++) {
        if (n - arr[i] >= 0) {
            n -= arr[i];
            ctr++;
        }
    }

    cout << ctr << "\n";
}