#include <bits/stdc++.h>
using namespace std;

#define MAXL 100100

char cadeia[MAXL];

bool process() {
    int i = 0;
    char c;
    bool def = true;
    stack<char> fila;
    while (true) {
        c = cadeia[i];
        if (c == '\0') break;
        if ((c == '(') || (c == '[') || (c == '{')) {
            fila.push(c);
        } else {
            if (fila.empty()) {
                def = false;
                break;
            }
            if (c == ')') {
                if (fila.top() == '(') {
                    fila.pop();
                } else {
                    def = false;
                    break;
                }
            } else if (c == ']') {
                if (fila.top() == '[') {
                    fila.pop();
                } else {
                    def = false;
                    break;
                }
            } else {
                if (fila.top() == '{') {
                    fila.pop();
                } else {
                    def = false;
                    break;
                }
            }
        }
        i++;
    }
    return def;
}

int main() {
    int T;
    scanf(" %d ", &T);
    for (int I = 0; I < T; I++) {
        scanf("%s", cadeia);
        bool ans = process();
        if (ans) printf("S\n");
        else printf("N\n");
    }    
}