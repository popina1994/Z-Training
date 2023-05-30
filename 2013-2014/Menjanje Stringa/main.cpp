#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
const int nmax = 200000, qmmax = 200000;
int main() {
    int n, q, question, changed = 1;
    char s[nmax+1];
    scanf("%d&d", &n ,&q);
    gets(s);
    for (int i = 0; i < q; i++) {
        scanf("%d", &question);
        if (question == 1) {
            int tempi;
            char tempc;
            scanf("%d%c", &tempi, &tempc);
            if (changed == 1)
                s[tempi-1] = tempc;
            else s[n-tempi] = tempc;
        } else changed = -changed;

    }system("pause");
    if (changed == 1)
        for (int i =0; i < n; i++) {
            printf("%c", s[i]);
        }
    else for(int i = n-1; i >= 0; i--)
            printf("%c", s[i]);
    return 0;
}
