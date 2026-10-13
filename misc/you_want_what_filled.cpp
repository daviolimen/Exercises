#include <bits/stdc++.h>
using namespace std;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

int N, M, counter;
char grid[50][51];
vector<pair<int, char>> holes;

bool cmp(pair<int, char> a, pair<int, char> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    } else {
        return a.first > b.first;
    }
}

bool isSafe(int y, int x) {
    if ((y < 0) || (y >= N) || (x < 0) || (x >= M)) return false;
    return true;
}

void floodFill(int y, int x, char b) {
    if (!isSafe(y, x)) return;
    if (grid[y][x] != b) return;
    grid[y][x] = '.';
    counter++;
    for (int i = 0; i < 4; i++) floodFill(y + dy[i], x + dx[i], b);
}

int main() {
    int problem = 1;
    scanf("%d%d", &N, &M);
    while (N != 0) {
        for (int i = 0; i < N; i++) {
            scanf("%s", grid[i]);
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] != '.') {
                    counter = 0;
                    char b = grid[i][j];
                    floodFill(i, j, b);
                    holes.emplace_back(counter, b);
                }
            }
        }
        sort(holes.begin(), holes.end(), cmp);
        printf("Problem %d:\n", problem);
        for (auto x : holes) {
            printf("%c %d\n", x.second, x.first);
        }
        holes.clear();
        problem++;
        scanf("%d%d", &N, &M);
    }
}