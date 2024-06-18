#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;

int n, k, arr[MAXN];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    sort(arr + 1, arr + n + 1, greater<int>());
    cout << arr[k] << "\n";
}