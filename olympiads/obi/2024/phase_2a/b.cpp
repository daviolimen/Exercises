#include <bits/stdc++.h>
using namespace std;

int main() {
    bool alfabeto[1000];
    memset(alfabeto, 0, sizeof(alfabeto));
    int k, n; cin >> k >> n;
    for (int i = 0; i < k; i++) {
        char c; cin >> c;
        alfabeto[(int) c] = 1;
    }

    bool ok = 1;
    string msg; cin >> msg;
    for (int i = 0; i < n; i++) {
        if (alfabeto[(int) msg[i]]) continue;
        ok = 0;
        break;
    }

    cout << ((ok) ? "S\n" : "N\n");
}