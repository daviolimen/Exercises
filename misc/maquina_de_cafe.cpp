#include <iostream>
using namespace std;

int main(){
	int a1, a2, a3, min;
	scanf("%d%d%d", &a1, &a2, &a3);
    min = 2 * a2 + 4 * a3;
    if ((2 * a1 + 2 * a3) < min) {
        min = 2 * a1 + 2 * a3;
    }
    if ((4 * a1 + 2 * a2) < min) {
        min = 4 * a1 + 2 * a2;
    }
    printf("%d\n", min);
    return 0;
}
