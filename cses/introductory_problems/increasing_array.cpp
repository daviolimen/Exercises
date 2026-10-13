#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    long long curr, prev, diff;
    long long moves = 0;
    cin >> n >> prev;
    for (int i = 0; i < n - 1; i++) {
        cin >> curr;
        if (curr < prev) {
            diff = prev - curr;
            moves += diff;
        } else {
            prev = curr;
        }
    }
    cout << moves << "\n";
}