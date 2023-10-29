#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

int n, t, arr[MAXN];

int main() {
    cin >> n >> t;
    for (int i = 0; i < n; i++) cin >> arr[i];

    int best = 0, currTime = 0;

    for (int i = 0, j = 0; (i < n) && (j <= n); i++) {
        while ((j < n) && (currTime + arr[j] <= t)) {
            currTime += arr[j++];
            best = max(best, j - i);
        }
        currTime -= arr[i];
    }

    cout << best << "\n";
}