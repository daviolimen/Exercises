#include <bits/stdc++.h>
using namespace std;

int main() {
    int danca;
    char texto[51];
    while (cin.getline(texto, 51)) {
        danca = 1;
        for (int i = 0; i <= 50; i++) {
            char c = texto[i];
            if (c == '\0') break;
            else if (c == ' ') printf("%c", c);
            else if (danca == 1) {
                if ('a' <= c && c <= 'z') printf("%c", c + 'A' - 'a');
                else printf("%c", c);
                danca = 0;
            } else {
                if ('A' <= c && c <= 'Z') printf("%c", c + 'a' - 'A');
                else printf("%c", c);
                danca = 1;
            }
        }
        printf("\n");
    }
    return 0;
}