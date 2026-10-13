#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 200000

int n, arr[MAXN];

ll solve() {
    unordered_map<ll, int> prevSums;
    ll res = 0;
    int currSum = 0;

    for (int i = 0; i < n; i++) {
        currSum += arr[i];
        currSum %= n;
        if (currSum < 0) currSum += n;

        if (currSum == 0) {
            res++;
        }

        if (prevSums.find(currSum) != prevSums.end()) {
            res += prevSums[currSum];
        }

        prevSums[currSum]++;
    }
    return res;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << solve() << "\n";
}