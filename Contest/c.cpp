#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200001;

long long n, k;
int arr[MAXN];

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) arr[i] = i;
        int idx = 1;
        while (k > 0) {
            if (k % 2) break;
            if ((n - 2 * idx + 1) * 2 <= 0) break;
            if (k >= (n - 2 * idx + 1) * 2) {
                k -= (n - 2 * idx + 1) * 2;
                swap(arr[idx], arr[n - idx + 1]);
                idx++;
            } else {
                int of = k / 2;
                k -= of * 2;
                swap(arr[idx], arr[idx + of]);
            }
        }

        if (k == 0) {
            cout << "Yes\n";
            for (int i = 1; i <= n; i++) cout << arr[i] << " \n"[i == n];
        } else cout << "No\n";
    }
}