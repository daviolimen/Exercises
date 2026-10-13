#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 200000

int n, arr[MAXN];

ll solve() {
    ll sum1 = 0, sum3 = 0, ans = 0;
    int l = -1, r = n;

    while (l < r - 1) {
        if (sum1 < sum3) {
            sum1 += arr[++l];
        } else if (sum1 > sum3) {
            sum3 += arr[--r];
        } else {
            if (l + 1 == r - 1) break;
            sum1 += arr[++l];
            sum3 += arr[--r];
        }
        if (sum1 == sum3) ans = sum1;
    }
    return ans;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << solve() << "\n";
}