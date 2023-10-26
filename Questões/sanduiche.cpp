#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000001

int N, D, C[MAXN];

int main() {
    cin >> N >> D;
    for (int i = 1; i <= N; i++) cin >> C[i];

    int res = 0, j = 1, sum = 0;

    for (int i = 1; i <= N; i++) {
        if (i > j) {
            sum += C[j++];
        }
        while ((j <= N) && (sum < D)) {
            sum += C[j++];
        }
        if (sum == D) res++;
        sum -= C[i];
    }

    sum = 0;
    for (int i = 2; i <= N; i++) sum += C[i];

    j = 2;
    for (int i = 1; i < N; i++) {
        sum += C[i];
        if (i == j) {
            sum -= C[j++];
        }
        while ((sum > D) && (j < N)) {
            sum -= C[j++];
        }
        if (sum == D) res++;
    }

    cout << res << "\n";
}