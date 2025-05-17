/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: fact4
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream cin ("fact4.in");
    ofstream cout ("fact4.out");
    int n; cin >> n;
    int ans = 1, cnt2 = 0, cnt5 = 0;
    for (int i = 1; i <= n; i++) {
        int cpy = i;
        while (cpy % 2 == 0) {
            cpy /= 2;
            cnt2++;
        }
        while (cpy % 5 == 0) {
            cpy /= 5;
            cnt5++;
        }
        ans *= cpy;
        ans %= 10;
    }
    cnt2 -= cnt5;
    while (cnt2--) ans = (ans * 2) % 10;
    cout << ans << "\n";
    return 0;
}