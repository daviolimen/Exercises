#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 100001

int n;
char arr[MAXN];

ll solve() {
    unordered_map<int, int> mp; // o negocio e perceber que a soma de l a r tem que ser: r - l + 1 = r - (l - 1), e a soma seria, = prefixSum[r] - prefixSum[l - 1], o meta é manter no mp
    ll res = 0;                 // o valor da soma - o valor da posicao
    int currSum = 0;

    for (int i = 1; i <= n; i++) {
        currSum += arr[i] - '0';

        if (currSum == i) {
            res++;
        }

        if (mp.find(currSum - i) != mp.end()) {
            res += mp[currSum - i];
        }

        mp[currSum - i]++;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false); ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> arr[i];
        cout << solve() << "\n";
    }
}