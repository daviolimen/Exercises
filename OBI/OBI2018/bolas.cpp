#include <bits/stdc++.h>
using namespace std;

int arr[8], ctr[10];

int main() {
    for (int i = 0; i < 8; i++) {
        cin >> arr[i];
        ctr[arr[i]]++;
    }

    bool pos = true;
    for (int i = 0; i < 10; i++) {
        if (ctr[i] > 4) {
            pos = false;
            break;
        }
    }

    cout << ((pos) ? "S\n" : "N\n");
}