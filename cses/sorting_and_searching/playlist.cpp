#include <bits/stdc++.h>
using namespace std;

#define MAXN 200000

int n, arr[MAXN];
set<int> used;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    int ans = 1;
    used.insert(arr[0]);

    for (int i = 0, j = 0; (i < n) && (j < n); i++) {
        while ((used.find(arr[j + 1]) == used.end()) && (j < n - 1)) {
            j++;
            used.insert(arr[j]);
            ans = max(ans, j - i + 1);
        }
        used.erase(arr[i]);
    }

    cout << ans << "\n";
}