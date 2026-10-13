#include <bits/stdc++.h>
using namespace std;

#define MAXN 5000

int n, x, sum2[MAXN];
pair<int, int> arr[MAXN];

tuple<int, int, int> sumOfTwo(int s, int j) {
    if (s <= 1) return {-1, -1, -1};
    int i = 0, k = n - 1;
    while (i < k) {
        int sum = arr[i].first + arr[k].first;
        if (sum == s) {
            if ((arr[i].second != j) && (arr[k].second != j)) {
                return {arr[i].second + 1, j + 1, arr[k].second + 1};
            } else {
                return {-1, -1, -1};
            }
        } else if (sum > s) {
            k--;
        } else {
            i++;
        }
    }
    return {-1, -1, -1};
}

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        arr[i].second = i;
        cin >> arr[i].first;
        sum2[i] = x - arr[i].first;
    }
    sort(arr, arr + n);
    tuple<int, int, int> ans;
    for (int i = 0; i < n; i++) {
        ans = sumOfTwo(sum2[i], i);
        if (get<0>(ans) != -1) break;
    }
    if ((get<0>(ans) == -1) || (get<0>(ans) == get<1>(ans)) || (get<0>(ans) == get<2>(ans)) || (get<1>(ans) == get<2>(ans))) cout << "IMPOSSIBLE\n";
    else cout << get<0>(ans) << " " << get<1>(ans) << " " << get<2>(ans) << "\n"; 
}