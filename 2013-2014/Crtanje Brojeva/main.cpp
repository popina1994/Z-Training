#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

const int strMax = 1000, rowMax = 9, colMax = 7, rStart = 4, cStart = 3;



char sRead[strMax+1], s[strMax+2], x[rowMax][colMax];

void setIndexS(char s[strMax+2], int &n) {
    for (int i = 0; i < strlen(s); i ++) {
        if ( (s[i] == '_') && (s[i+1] != '^') ) {
            n = i + 1;
            break;
        }
    }
}

void moveLeft()

int main() {
    freopen("ulaz.in", "r", stdin);
    int n, r, c, sIndex;
    bool left, down;
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        scanf("%s", &sRead);
        s[0] = '_';
        memcpy(s + 1, sRead, sizeof(sRead));
        memset(x, 0, sizeof(x));
        r = rStart; c = cStart;
        setIndexS(s, sIndex);

    }
    return 0;
}
