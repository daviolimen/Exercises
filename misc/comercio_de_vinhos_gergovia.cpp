#include <bits/stdc++.h>
using namespace std;

#define MAXN 100100
typedef long long ll;

int n, arr[MAXN];

ll trabalho() {
    ll garrafas = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        garrafas += arr[i];
        ans += abs(garrafas);
    }
    return ans;
}

int main() {
    cin >> n;
    while (n != 0) {
        for (int i = 1; i <= n; i++) cin >> arr[i];
        cout << trabalho() << "\n";
        cin >> n;
    }

}