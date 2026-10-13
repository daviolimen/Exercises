#include <bits/stdc++.h>
using namespace std;

#define MAXW 51
#define MAXH 50

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

int w, h, ans;
char image[MAXH][MAXW];

bool isSafe(int y, int x) {
    if ((y < 0) || (y >= h) || (x < 0) || (x >= w) || (image[y][x] == '.')) return false;
    return true;
}

void floodFill(int y, int x) {
    if (!isSafe(y, x)) return;
    if (image[y][x] == 'X') image[y][x] = '#';
    else return;
    for (int i = 0; i < 4; i++) floodFill(y + dy[i], x + dx[i]);
}

void dfs(int y, int x) {
    if (!isSafe(y, x)) return;
    if (image[y][x] == '.' || image[y][x] == '#') return;

    if (image[y][x] == 'X') {
        floodFill(y, x);
        ans++;
    } else if (image[y][x] == '*') image[y][x] = '#';

    for (int i = 0; i < 4; i++) {
        dfs(y+dy[i], x+dx[i]);
    }
}

int main() {
    int counter = 1;
    vector<int> score;
    scanf("%d%d", &w, &h);
    while (w != 0) {
        if (counter != 1) printf("\n");
        for (int i = 0; i < h; i++) {
            scanf("%s", image[i]);
        }
        score.clear();
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (image[i][j] == 'X') {
                    ans = 0;
                    dfs(i, j);
                    score.push_back(ans);
                }
            }
        }
        printf("Throw %d\n", counter);
        sort(score.begin(), score.end());
        for (int i = 0; i < score.size() - 1; i++) {
            printf("%d ", score[i]);
        }
        printf("%d\n", score[score.size() - 1]);
        counter++;
        scanf("%d%d", &w, &h);
    }
    return 0;
}