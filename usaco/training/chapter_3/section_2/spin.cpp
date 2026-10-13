/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: spin
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

int pos[5], speed[5], wedges[5][5][2];

int main() {
    memset(wedges, -1, sizeof(wedges));
    ifstream cin ("spin.in");
    ofstream cout ("spin.out");
    for (int i = 0; i < 5; i++) {
        cin >> speed[i];
        int W; cin >> W;
        for (int j = 0; j < W; j++) {
            cin >> wedges[i][j][0] >> wedges[i][j][1];
        }
    }

    int ans = -1;

    for (int s = 0; s < 360; s++) {
        bool nice = 0;
        for (int r = 0; r < 360; r++) {
            bool ok = 1;
            for (int i = 0; i < 5; i++) {
                bool ok2 = 0;
                for (int j = 0; j < 5; j++) {
                    if (wedges[i][j][0] == -1) break;
                    int posi = (wedges[i][j][0] + pos[i]) % 360;
                    int posf = (posi + wedges[i][j][1]) % 360;
                    if (posi <= posf) {
                        if ((posi <= r) && (r <= posf)) ok2 = 1;
                    } else {
                        if ((posi <= r) || (r <= posf)) ok2 = 1;
                    }
                }
                if (!ok2) ok = 0;
            }
            if (ok) nice = 1;
        }
        if (nice) {
            ans = s;
            break;
        }
        for (int i = 0; i < 5; i++) pos[i] = (pos[i] + speed[i]) % 360;
    }

    if (ans == -1) cout << "none\n";
    else cout << ans << "\n";
    return 0;
}