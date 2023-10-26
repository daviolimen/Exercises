#include <bits/stdc++.h>
using namespace std;

#define MAXN 1001

int n, arr[MAXN];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    bool solve = false;

    for (int i = 1; i <= n; i++) {
        if (arr[i] == 0) {
            solve = true;
            swap(arr[i], arr[n]);
            break;
        }
        if ((arr[i] == 5) && (arr[n] > 5)) {
            solve = true;
            swap(arr[i], arr[n]);
            break;
        }
    }

    if (!solve) {
        for (int i = n; i > 0; i--) {
            if (arr[i] == 5) {
                solve = true;
                swap(arr[i], arr[n]);
                break;
            }
        }
    }

    if (!solve) cout << "-1\n";
    else {
        for (int i = 1; i <= n; i++) cout << arr[i] << " \n"[i == n];
    }
}