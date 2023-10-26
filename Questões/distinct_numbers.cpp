#include <bits/stdc++.h>
using namespace std;

int n, arr[200000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    int last = arr[0], counter = 1;
    for (int i = 1; i < n; i++) {
        if (last == arr[i]) continue;
        counter++;
        last = arr[i];
    }
    cout << counter << "\n";
}