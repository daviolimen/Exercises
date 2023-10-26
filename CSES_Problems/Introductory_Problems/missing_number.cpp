#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    long long missing = (long long) n * (n + 1) / 2;
    for (int i = 0; i < n - 1; i++) {
        int a;
        cin >> a;
        missing -= a;
    }
    cout << missing << "\n";
}