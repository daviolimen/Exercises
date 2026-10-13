#include <bits/stdc++.h>
using namespace std;

#define MAXN 500100
typedef long long ll;

int N, K, arr[MAXN];

ll numOfSubarrsWithSumK() {
    unordered_map<int, int> prevSums;
    ll res = 0;
    int currSum = 0;
    for (int i = 0; i < N; i++) {
        currSum += arr[i];
        if (currSum == K) {
            res++;
        }
        if (prevSums.find(currSum - K) != prevSums.end()) {
            res += (prevSums[currSum - K]);
        }
        prevSums[currSum]++;
    }
    return res;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> arr[i];
    cout << numOfSubarrsWithSumK() << "\n";
}