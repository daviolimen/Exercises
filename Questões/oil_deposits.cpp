#include <bits/stdc++.h>
using namespace std;

#define MAXM 100
#define MAXN 101

int M, N;
char grid[MAXM][MAXN];

int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void flood_fill(int i, int j) {
    grid[i][j] = '*';
    int i2, j2;
    for (int d = 0; d < 8; d++) {
        i2 = i + dy[d];
        j2 = j + dx[d];
        if ((i2 < 0) or (i2 >= M) or (j2 < 0) or (j2 >= N)) {
            continue;
        } else {
            if (grid[i2][j2] == '@') flood_fill(i2, j2);
        }
    }
}

int main() {
    scanf("%d%d", &M, &N);
    while (M != 0) {
        for (int i = 0; i < M; i++) {
            scanf("%s", grid[i]);
        }
        int counter = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == '*') continue;
                flood_fill(i, j);
                counter++;
            }
        }
        printf("%d\n", counter);
        scanf("%d%d", &M, &N);
    }
}