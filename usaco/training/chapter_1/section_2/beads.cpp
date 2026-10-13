/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: beads
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream cin ("beads.in");
    ofstream cout ("beads.out");
    int n; cin >> n;
    string s; cin >> s;
    s += s;

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int ctr = 1;
        int j, k;
        char color = s[i];
        for (j = i + 1; j < i + n; j++) {
            if (s[j] == 'w') {
                ctr++;
                continue;
            }
            if (color == 'w') color = s[j];
            if (s[j] == ((color == 'b') ? 'r' : 'b')) break;
            ctr++;
        }
        
        if (j < i + n - 1) ctr++;
        color = s[i + n - 1];

        for (k = i + n - 2; k >= j; k--) {
            if (s[k] == 'w') {
                ctr++;
                continue;
            }
            if (color == 'w') color = s[k];
            if (s[k] == ((color == 'b') ? 'r' : 'b')) break;
            ctr++;
        }
        ans = max(ans, ctr);
    }

    cout << ans << "\n";

    return 0;
}