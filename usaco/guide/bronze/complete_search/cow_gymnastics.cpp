#include <bits/stdc++.h>
using namespace std;

#define MAXK 11
#define MAXN 21

int K, N, sessions[MAXK][MAXN];
bool firstSession[MAXN][MAXN];

int main() {
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    cin >> K >> N;
    for (int i = 1; i <= K; i++) {
        for (int j = 1; j <= N; j++) {
            int a; cin >> a;
            sessions[i][a] = j;
        }
    }

    for (int i = 1; i < N; i++) {
        for (int j = i + 1; j <= N; j++) {
            firstSession[i][j] = sessions[1][i] < sessions[1][j];
        }
    }

    int ctr = 0;
    for (int i = 1; i < N; i++) {
        for (int j = i + 1; j <= N; j++) {
            bool consis = true;
            for (int k = 2; k <= K; k++) {
                if ((sessions[k][i] < sessions[k][j]) != firstSession[i][j]) {
                    consis = false;
                    break;
                }
            }
            if (consis) ctr++;
        }
    }

    cout << ctr << "\n";
}