#include <iostream>

using namespace std;

int main(){
	int n, a, k;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		arr[i] = a;
	}
	scanf("%d", &k);
    int i = 0;
    int j = n - 1;
    int sum = arr[i] + arr[j];
    while (sum != k) {
        if (sum < k) {
            i++;
        }
        else {
            j--;
        }
        sum = arr[i] + arr[j];
    }
    cout << arr[i] << " " << arr[j] << "\n";
}
