#include <bits/stdc++.h>
using namespace std;

int n, ctr[101];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        ctr[a]++;
    }

    int nota, best = -1;

    for (int i = 0; i <= 100; i++) {
        if (ctr[i] >= best) {
            nota = i;
            best = ctr[i];
        }
    }

    cout << nota << "\n";
}