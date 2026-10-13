#include <bits/stdc++.h>
using namespace std;

#define MAXN 200000

int n;
pair<int, int> arr[MAXN];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].second >> arr[i].first;
    }

    sort(arr, arr + n);

    int ctr = 1, prev = arr[0].first;
    for (int i = 1; i < n; i++) {
        if (arr[i].second >= prev) {
            ctr++;
            prev = arr[i].first;
        }
    }

    cout << ctr << "\n";
}