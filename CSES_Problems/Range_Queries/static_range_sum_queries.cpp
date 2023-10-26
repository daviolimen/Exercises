#include <bits/stdc++.h>
using namespace std;
 
#define MAXN 200100
 
int n, q, arr[MAXN];
long long prefix_sum[MAXN];
 
int main() {
    int a, b, c;
    long long sum = 0;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> c;
        sum += c;
        prefix_sum[i] = sum;
        arr[i] = c;
    }
    for (int i = 1; i <= q; i++) {
        cin >> a >> b;
        cout << (prefix_sum[b] - prefix_sum[a - 1]) << "\n";
    }
}