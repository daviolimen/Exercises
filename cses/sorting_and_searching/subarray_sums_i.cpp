// ha uma solucao com two pointers ja que os elementos sao todos positivos, mas como o subarray sums II pede com negativos, essa solucao ja resolve os dois

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 200000

int n, x, a[MAXN];

ll numOfSubarrSums() {
    unordered_map<ll, int> prevSums;
    ll currSum = 0, res = 0;

    for (int i = 0; i < n; i++) {
        currSum += a[i];

        if (currSum == x) {
            res++;
        }

        if (prevSums.find(currSum - x) != prevSums.end()) {
            res += prevSums[currSum - x];
        }

        prevSums[currSum]++;
    }
    return res;
}

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << numOfSubarrSums() << "\n";
}