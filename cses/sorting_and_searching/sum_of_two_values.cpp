#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 1;

int n, x;
pair<int, int> arr[MAXN];

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }

    sort(arr + 1, arr + n + 1);

    int i = 1, j = n, sum = arr[i].first + arr[j].first;
    bool sol = false;
    while (i < j) {
        sum = arr[i].first + arr[j].first;
        if (sum == x) {
            sol = true;
            break;
        }
        else if (sum > x) j--;
        else i++;
    }

    if (sol) cout << arr[i].second << " " << arr[j].second << "\n";
    else cout << "IMPOSSIBLE\n";
}