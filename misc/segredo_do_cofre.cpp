#include <bits/stdc++.h>
using namespace std;

#define MAXN 100010

int N, M, prefix_sums[MAXN][10], resposta[10], temp[10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, prev, curr;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> a;
        temp[a]++;
        copy(temp, temp+10, prefix_sums[i]);
    }
    
    cin >> prev;
    for (int i = 1; i < M; i++) {
        cin >> curr;
        if (i == 1) {
            for (int j = 0; j < 10; j++) {
                resposta[j] += prefix_sums[curr][j];
            }
        } else {
            if (curr > prev) {
                for (int j = 0; j < 10; j++) {
                    resposta[j] += prefix_sums[curr][j] - prefix_sums[prev][j];
                }
            } else {
                for (int j = 0; j < 10; j++) {
                    resposta[j] += prefix_sums[prev - 1][j] - prefix_sums[curr - 1][j];
                }
            }
        }
        prev = curr;
    }
    for (int i = 0; i < 10; i++) cout << resposta[i] << " \n"[i==9];
}