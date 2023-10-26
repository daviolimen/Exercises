#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAXN 200000

int n, arr[MAXN];

ll kadane() {
    ll maxSoFar = INT_MIN, currSum = 0;
    for (int i = 0; i < n; i++) {
        currSum += arr[i];
        maxSoFar = max(maxSoFar, currSum);
        if (currSum < 0) {
            currSum = 0;
        }
    }
    return maxSoFar;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << kadane() << "\n";
}