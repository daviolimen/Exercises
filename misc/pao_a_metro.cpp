#include <bits/stdc++.h>
using namespace std;

int N, K, arr[10010];

bool ok(int a) {
    int ctr = 0;
    for (int i = 1; i <= K; i++) {
        ctr += (int) arr[i] / (int) a;
    }
    return ctr >= N;
}

int ans() {
    int ini = 1, fim = 10001;
    int ans;
    while (ini <= fim) {
        int mid = (ini + fim) / 2;
        if (ok(mid)) {
            ans = mid;
            ini = mid + 1;
        } else {
            fim = mid - 1;
        }
    }
    return ans;
}

int main() {
    cin >> N;
    cin >> K;
    for (int i = 1; i <= K; i++) cin >> arr[i];
    cout << ans() << "\n";
}