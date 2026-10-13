/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: davideo2
TASK: ttwo
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
using namespace std;

const int DY[] = {-1, 0, 1, 0};
const int DX[] = {0, 1, 0, -1};

int ctr, state[2][3];
char grid[10][10];
bool visited[10][10][4][10][10][4];

bool notSafe(int y, int x) {
    if ((grid[y][x] == '*') || (y < 0) || (x < 0) || (y >= 10) || (x >= 10)) return 1;
    return 0;
}

bool mover(int sel) {
    int d = state[sel][2];
    int ny = state[sel][0] + DY[d];
    int nx = state[sel][1] + DX[d];
    if (notSafe(ny, nx)) state[sel][2] = (state[sel][2] + 1) % 4;
    else {
        state[sel][0] = ny;
        state[sel][1] = nx;
    }
    return true;
}

bool process() {
    if ((state[0][0] == state[1][0]) && (state[0][1] == state[1][1])) return 1;
    ctr++;
    mover(0);
    mover(1);
    return 0;
}

int main() {
    ifstream cin ("ttwo.in");
    ofstream cout ("ttwo.out");
    state[0][2] = 0, state[1][2] = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'C') state[0][0] = i, state[0][1] = j;
            if (grid[i][j] == 'F') state[1][0] = i, state[1][1] = j;
        }
    }

    bool ok = 0;
    for (int i = 0; i < 1000000; i++) {
        if (process()) {
            ok = 1;
            break;
        }
    }

    if (ok) cout << ctr << "\n";
    else cout << "0\n";
    return 0;
}