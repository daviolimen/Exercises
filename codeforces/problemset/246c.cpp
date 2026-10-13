#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());



    int ctr = 0;

    for (int i = 0; i < n; i++) {
        if (ctr == k) break;
        cout << "1 " << a[i] << "\n";
        ctr++;
    }
    for (int i = n - 1; i >= 0; i--) {
        bool complete = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (ctr == k) {
                complete = 1;
                break;
            }
            int qnt = n - i + 1;
            cout << qnt;
            for (int k = n - 1; k >= i; k--) cout << " " << a[k];
            cout << " " << a[j] << "\n";
            ctr++;
        }
        if (complete) break;
    }
}