#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000

int n, arr[MAXN];

int main() {
    cin >> n;
    int sub = 0, con = 0;
    for (int i = 0; i < n; i++) {
        int h; cin >> h;
        if (h < 50) sub++;
        else if (h < 85) con++;
    }

    cout << sub << " " << con << "\n";
}