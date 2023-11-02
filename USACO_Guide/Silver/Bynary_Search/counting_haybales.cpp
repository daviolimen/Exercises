#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

int N, Q, arr[MAXN];

int query(int a, int b) {
    int it1 = lower_bound(arr, arr + N, a) - arr;
    int it2 = upper_bound(arr, arr + N, b) - arr;
    return (it2 - it1);
}

int main() {
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    cin >> N >> Q;
    for (int i = 0; i < N; i++) cin >> arr[i];

    sort(arr, arr + N);

    while (Q--) {
        int a, b; cin >> a >> b;
        cout << query(a, b) << "\n";
    }
}