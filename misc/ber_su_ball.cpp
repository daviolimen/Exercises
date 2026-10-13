#include <bits/stdc++.h>
using namespace std;

#define MAXN 100

int n, m, boys[MAXN], girls[MAXN];

int solve() {
    int a = 0, b = 0, ctr = 0;
    while ((a < n) && (b < m)) {
        if (abs(boys[a] - girls[b]) <= 1) {
            ctr++;
            a++;
            b++;
        } else if (boys[a] > girls[b]) {
            b++;
        } else {
            a++;
        }
    }
    return ctr;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> boys[i];
    cin >> m;
    for (int i = 0; i < m; i++) cin >> girls[i];
    sort(boys, boys+n);
    sort(girls, girls+m);
    cout << solve() << "\n";
}