#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

const int lenMatrixMax = 11,
           jmpMax = 8,
           rJmp[jmpMax] = {2, 2, -2, -2, 1, 1, -1, -1},
           cJmp[jmpMax] = {-1, 1, -1, 1, 2, -2, 2, -2};

int n, m, r, c, k, x[lenMatrixMax][lenMatrixMax] ;

/**< n broj vrsta, m broj kolona, r, c poziciju, k broj skokova */

bool isLegal(int r, int c, int n, int m) {
    return ( (r >= 1) && (r <= n) && (c >= 1) && (c <= m) );
}

void setNewMatrix(int n, int m, int r, int c, int xNew[][lenMatrixMax], int &nNew, int &mNew, int &rStart, int &cStart) {
    // rStart, cStart nova matrica, nNew, mNew velicina nove matrice, xNew nova matrica
    memset(xNew, 0, sizeof(xNew));
    rStart = r;
    cStart = c;
    mNew = m;
    nNew = n;
    if (m > lenMatrixMax - 1)  mNew = lenMatrixMax - 1;
    if (n > lenMatrixMax - 1)  nNew = lenMatrixMax - 1;
    if (r > 5) {
        rStart = 5;
        nNew = n - (r - rStart);
    }
    if (c > 5) {
        cStart = 5;
        mNew = m - (c - cStart);
    }
}

void jmp(int x[][lenMatrixMax], int r, int c, int n, int m, int lenJmp, int tmpLen) {
    if (tmpLen < lenJmp) {
        for (int k = 0; k < jmpMax; k ++)
            if (isLegal(r + rJmp[k], c + cJmp[k], n, m))
                jmp(x, r + rJmp[k], c + cJmp[k], n, m, lenJmp, tmpLen + 1);
    }
    else if (tmpLen == lenJmp)
        x[r][c] = 1;
}

int main() {
    freopen("ulaz.in", "r", stdin);
    freopen("izlaz.out", "w", stdout);
    scanf("%d%d%d%d%d", &n, &m, &r, &c, &k);
    int counter = 0, mNew, nNew, cStart, rStart;
    setNewMatrix(n, m, r, c, x, nNew, mNew, rStart, cStart);
    jmp(x, rStart, cStart, nNew, mNew, k, 0);
    for (int rCount = 1; rCount <= nNew; rCount ++)
        for (int cCount = 1; cCount <= mNew; cCount ++)

            if (x[rCount][cCount] == 1)
                counter ++;
    printf("%d", counter);
    return 0;
}
