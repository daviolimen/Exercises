#include <bits/stdc++.h>
using namespace std;

int main() {
    int tt; cin >> tt;
    while (tt--) {
        string num; cin >> num;
        int x = stoi(num);
        int l = 0, r = 100;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (m * m <= x) l = m;
            else r = m;
        }
        
        if (l * l != x) {
            cout << "-1\n";
        } else {
            cout << "0 " << l << "\n";
        }
    }
}