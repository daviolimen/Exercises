#include <bits/stdc++.h>
using namespace std;
 
#define MAXN 200000
 
int arr[MAXN];
 
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += abs(arr[i] - arr[n / 2]);
	}
	cout << ans << "\n";
}