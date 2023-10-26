#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, counter = 0;
    char c;
    cin >> n;
    while ((c = getchar()) != EOF) {
        if (c == '{') {
            counter++;
        } else if (c == '}') {
            counter--;
        }
        if (counter < 0) {
            printf("N\n");
            return 0;
        }
    }
    if (counter == 0) printf("S\n");
    else printf("N\n");
}