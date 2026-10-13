#include <bits/stdc++.h>
using namespace std;

#define MAXN 400000

int n;
pair<int, int> arr[MAXN];
bool visited[MAXN];

int main() {
    ios::sync_with_stdio(false); ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    int cst = 0;
    for (int i = 0; i < (2 * n); i += 2) {
        cin >> arr[i].first;
        cin >> arr[i+1].first;
        arr[i].second = arr[i+1].second = cst++;
    }

    sort(arr, arr + (2 * n));

    int ctr = 0, best = 0;

    for (int i = 0; i < (2 * n); i++) {
        if (visited[arr[i].second]) {
            ctr--;
        } else {
            visited[arr[i].second] = true;
            ctr++;
            best = max(best, ctr);
        }
    }

    cout << best << "\n";
}