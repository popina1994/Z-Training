#include <iostream>
#include <cstdio>
#include <cstring>
#define DEBUG 1

using namespace std;

const int NUM_MAX = 1000, QUERY_MAX = 1000000;

int n, q, meme1[NUM_MAX][NUM_MAX + 1] = {0}, meme2[NUM_MAX][NUM_MAX+1] = {0};

char s1[NUM_MAX + 1], s2[NUM_MAX + 1];

void OutputMatrix(int x[][NUM_MAX + 1], int numRow, int numCol) {
    for (int row = 0; row < numRow; row ++) {
        for (int col = 0; col < numCol; col ++)
            cout << x[row][col] << " ";
        cout << endl;
    }
}

void MakeMeme (int x[][NUM_MAX + 1], char s1[], char s2[]) {
    int l1 = strlen(s1);

    for (int row = 0; row < l1; row++) {
        x[row][0] = 0;
        for (int col = 1; col <= l1 - row; col++)
            x[row][col] = x[row][col - 1] +
                          (s1[col-1] == s2[row + col - 1]);
    }
}

int main() {
    if (DEBUG) {
        freopen("ulaz.in", "r", stdin);
        freopen("izlaz.out", "w", stdout);
    }

    scanf("%d", &n);

    scanf("%s%s", s1, s2);


    MakeMeme(meme1, s1, s2);
    MakeMeme(meme2, s2, s1);

    scanf("%d", &q);

    for (int idxTest = 0; idxTest < q; idxTest++) {

        int begin1, begin2, length, sol;
        scanf("%d%d%d", &begin1, &begin2, &length);
        begin1--;
        begin2--;

        if (begin1 <= begin2) {
            sol = meme1[begin2 - begin1][begin1 + length] - meme1[begin2 - begin1][begin1];
        } else
            sol = meme2[begin1 - begin2][begin2 + length] - meme2[begin1 - begin2][begin2];
        cout << sol << endl;
    }

    return 0;
}
