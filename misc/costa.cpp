#include <iostream>
using namespace std;

int main(){
	int m, n;
	char c;
	int ans = 0;
	scanf("%d%d", &m, &n);
	char matrix[m][n];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c;
			matrix[i][j] = c;
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] == '#') {
				if ((i == 0) || (i == m - 1) || (j == 0) || (j == n - 1)) {
					ans++;
				} else if ((matrix[i + 1][j] == '.') || (matrix[i - 1][j] == '.') || (matrix[i][j + 1] == '.') || (matrix[i][j - 1] == '.')) {
					ans++;
				}
			}
		}
	}
	printf("%d\n", ans);
    return 0;
}
