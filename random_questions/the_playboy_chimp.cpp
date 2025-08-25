#include <bits/stdc++.h>
using namespace std;

int N, Q, q, arr[50100];

int greaterLessThanK(int K) {
    int ini = 0, fim = N - 1;
    int ans = -1;
    while (ini <= fim) {
        int mid = (ini + fim) / 2;
        if (arr[mid] < K) {
            ans = arr[mid];
            ini = mid + 1;
        } else {
            fim = mid - 1;
        }
    }
    return ans;
}

int lesserGreaterThanK(int K) {
    int ini = 0, fim = N - 1;
    int ans = -1;
    while (ini <= fim) {
        int mid = (ini + fim) / 2;
        if (arr[mid] > K) {
            ans = arr[mid];
            fim = mid - 1;
        } else {
            ini = mid + 1;
        }
    }
    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> q;
        int a = greaterLessThanK(q);
        if (a == -1) cout << "X ";
        else cout << a << " ";
        int b = lesserGreaterThanK(q);
        if (b == -1) cout << "X\n";
        else cout << b << "\n";
    }
}