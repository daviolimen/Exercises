#include <bits/stdc++.h>
using namespace std;

#define MAXN 200000

int n, x, arr[MAXN];

long long solve() {
    unordered_map<long long, long long> mp;
    long long currSum = 0, res = 0;

    for (int i = 0; i < n; i++) {
        currSum += arr[i];

        if (currSum == x) {
            res++;
        }

        if (mp.find(currSum - x) != mp.end()) {
            res += mp[currSum - x];
        }

        mp[currSum]++;
    }

    return res;
}

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << solve() << "\n";
}