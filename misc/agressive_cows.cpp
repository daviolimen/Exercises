#include <bits/stdc++.h>
using namespace std;

#define MAXN 100100

int N, C, arr[MAXN];

bool check(int d) {
    int ctr = 1, prev = arr[0];
    for (int i = 1; i < N; i++) {
        if ((arr[i] - prev) >= d) {
            ctr++;
            prev = arr[i];
        }
    }
    return ctr >= C;
}

int bsearch() {
    int ini = 1, fim = 1000000000, meio, ans;
    while (ini <= fim) {
        meio = (ini + fim) / 2;
        if (check(meio)) {
            ans = meio;
            ini = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    for (int I = 0; I < t; I++) {
    cin >> N >> C;
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);
    cout << bsearch() << "\n";
    }

}