#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
typedef long long ll;

int N, arr[MAXN];

ll subarrsWithSumK(int K) {
    ll soma = 0, res = 0;
    unordered_map<ll, ll> prevSums;
    for (int i = 0; i < N; i++) {
        soma += arr[i];
        if (soma == K) {
            res++;
        }
        if (prevSums.find(soma - K) != prevSums.end()) {
            res += prevSums[soma - K];
        }
        prevSums[soma]++;
    }
    return res;
}

int main() {
    cin >> N;
    int a;
    ll soma = 0;
    for (int i = 0; i < N; i++) {
        cin >> a;
        soma += a;
        arr[i] = a;
    }
    if (soma % 2 == 1) {
        cout << "N\n";
    } else {
        ll test = 0, obj = soma / 2;
        bool start = false;
        for (int i = 0; i < N; i++) {
            if (test == obj) {
                start = true;
                break;
            }
            test += arr[i];
        }
        ll num = subarrsWithSumK(obj);
        if (start) num--;
        if (num >= 2) cout << "S\n";
        else cout << "N\n";
    }
}