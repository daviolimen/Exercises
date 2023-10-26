#include <bits/stdc++.h>
using namespace std;

int P1[4];
int P2[4];

int check_collision() {
    if ((P1[0] >= P2[0] && P1[0] <= P2[2]) || (P1[2] >= P2[0] && P1[2] <= P2[2])) {
        if ((P1[1] >= P2[1] && P1[1] <= P2[3]) || (P1[3] >= P2[1] && P1[3] <= P2[3])) {
            return 1;
        }
    } else if ((P2[0] >= P1[0] && P2[0] <= P1[2]) || (P2[2] >= P1[0] && P2[2] <= P1[2])) {
        if ((P2[1] >= P1[1] && P2[1] <= P1[3]) || (P2[3] >= P1[1] && P2[3] <= P1[3])) {
            return 1;
        }
    }
    return 0;
}


int main() {
    scanf("%d%d%d%d", &P1[0], &P1[1], &P1[2], &P1[3]);
    scanf("%d%d%d%d", &P2[0], &P2[1], &P2[2], &P2[3]);
    int ans = check_collision();
    printf("%d\n", ans);
}