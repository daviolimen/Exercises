#include <bits/stdc++.h>
using namespace std;

#define SQR(x) ((x) * (x))

#define MAXN 5000

int n, x[MAXN], y[MAXN];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }
    
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            ans = max(ans, (SQR(x[i] - x[j]) + SQR(y[i] - y[j])));
        }
    }
    cout << ans << "\n";
}