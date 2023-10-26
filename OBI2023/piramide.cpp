#include <bits/stdc++.h>
using namespace std;

int arr[6];

int main() {
    for (int i = 0; i < 6; i++) cin >> arr[i];

    sort(arr, arr + 6);

    int soma = arr[0] + arr[1] + arr[2] + arr[3] + arr[4];

    bool ok = false;

    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if ((arr[5] == arr[i] + arr[j]) && (arr[5] == (soma - arr[i] - arr[j]))) {
                ok = true;
                break;
            }
        }
    }

    cout << ((ok) ? "S\n" : "N\n");
}