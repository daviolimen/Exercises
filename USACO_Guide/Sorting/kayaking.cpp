#include <bits/stdc++.h>
using namespace std;
 
#define MAXN 50
 
int n, w[2 * MAXN];
 
int main() {
    cin >> n;
    n *= 2;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
 
    sort(w, w + n);
 
    int best = INT_MAX;
 
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int total = 0;
            vector<int> temp;

            for (int k = 0; k < n; k++) {
                if ((k == i) || (k == j)) continue;
                temp.push_back(w[k]);
            }

            for (int k = 0; k < n - 2; k += 2) {
                total += temp[k + 1] - temp[k];
            }
 
            best = min(best, total);
        }
    }
 
    cout << best << "\n";
}