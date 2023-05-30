#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

const int nameNumMax = 23762752, nMax = 1000000, nameMax = 10, numChar = 26;

int nameNum[nameNumMax];

bool Palindrom(char s[]) {
/**< Vraca tacno ako je string palindrom, inace false */
    int len = strlen(s);
    for (int i = 0; i <= len / 2; i ++)
        if (s[i] != s[len - i-1])
            return false;
    return true;
}

void LowerCase(char s[]) {
/**< pretvara sve cifre stringa u mala slova */
    int len = strlen(s);
    for (int i = 0; i < len; i ++)
        if (s[i] <= 'Z')
            s[i] = char(s[i] + 'a' - 'A');
}

int CharCrypt(char []) {
    /**< pretvara string u broj */
    int len = strlen(s), tmpNum = 0, tmpMul = 1;
    for (int i = 0; i <= len / 2; i ++) {
        tmpNum += tmpMul * (s[i] - 'a');
        tmpMul *= numChar;
    }
    if (len % 2 == 1)
        tmpNum += tmpMul;
}

void IntDecrypt(char s[], int num) {
    for (int i = 0; (i < nameMax / 2) && (); i ++) {
        s[i] =
    }
}

int main() {
    freopen("ulaz.in", "r", stdin);
    int n, tmpMax = 0, tmpIndexCrypt, tmpIndex;
    char s[nameMax+1];
    scanf("%d", &n);
    memset(nameNum, 0, sizeof(nameNum));

    for (int i = 0; i < n; i ++) {
        scanf("%s", &s);
        if (Palindrom(s)) {
            LowerCase(s);
            tmpIndexCrypt = CharCrypt(s);
            nameNum[tmpIndexCrypt] ++;
            if (nameNum[tmpIndexCrypt] > tmpMax) {
                tmpMax = nameNum[tmpIndexCrypt];
                tmpIndex = tmpIndexCrypt;
            }
        }
        IntDecrypt(s, tmpIndex);
        printf("%s", s);
    }
    return 0;
}
