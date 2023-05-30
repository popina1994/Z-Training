#include <iostream>
#include <cstdio>

using namespace std;

const int nmax = 2e5;

char s[3*nmax + 1];

int n, q;
// n - duzina stringa, q - broj upita

void print(int a, int begin, int end) {
    if (a == 1)
        for (int i = begin + 1; i < end; i++)
            printf("%c", s[i]);
    else for (int i = end - 1; i > begin; i--)
            printf("%c", s[i]);
}

int main() {
    int a = 1, f, j = 0, begin = nmax - 1, end; // a oznacava  da li je string obrnut ili ne, f koje klase je upit
    scanf("%d%d", &n, &q);
    scanf("%s", &s);
    end = nmax + n;
    for (int i = 0; i < n; i++)
        s[nmax+i] = s[i];
    for (int i = 0; i < q; i++) {
        scanf("%d", &f);
        if (f == 2)
            a = -a;
        if (f == 3) {
            char c;
            scanf(" %c", &c);
            if (a == 1)
                s[end++] = c;
            else s[begin--] = c;
        }
        if (f == 1) {
            int tempn;
            char c;
            scanf("%d %c", &tempn, &c);
            if (a == 1)
                s[begin + tempn] = c;
            else
                s[end - tempn] = c;
        }
    }
    print(a, begin, end);
    return 0;
}
