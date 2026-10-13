#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    ll res = 1;
    for (int i = 0; i < n; i++) {
        res = (res * 2) % (1000000007);
    }
    printf("%lld\n", res);
}