#include <bits/stdc++.h>
using namespace std;

int arr[3];

int main() {
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    for (int i = 0; i < 3; i++) cin >> arr[i];

    sort(arr, arr + 3);

    int minA, maxA;
    if ((arr[2] == arr[1] + 1) && (arr[1] == arr[0] + 1)) minA = 0;
    else if ((arr[1] == arr[0] + 2) || (arr[2] == arr[1] + 2)) minA = 1;
    else minA = 2;

    maxA = max(arr[1] - arr[0] - 1, arr[2] - arr[1] - 1);

    cout << minA << "\n" << maxA << "\n";
}