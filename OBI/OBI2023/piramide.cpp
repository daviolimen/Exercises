#include <bits/stdc++.h>
using namespace std;

int arr[6];

int main() {
    int sum = 0;
    for (int i = 0; i < 6; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr, arr + 6);
    bool test = false;
    do {
        if ((arr[0] == (arr[1] + arr[2])) && (arr[0] == (arr[3] + arr[4] + arr[5]))) {
            test = true;
            break;
        }
    } while (next_permutation(arr, arr + 6));

    cout << ((test) ? "S\n" : "N\n");
}