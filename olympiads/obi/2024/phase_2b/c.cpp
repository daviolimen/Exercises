#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    sort(A.begin(), A.end());

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int idx = lower_bound(A.begin(), A.end(), A[i] + A[j]) - A.begin();
            ans += idx - j - 1;
        }
    }
    
    cout << ans << "\n";
}