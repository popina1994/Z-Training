#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

const int nMax = 100000;

int num[nMax];

int CharToInt(char c) {
    return c - '0';
}

int main() {
    unsigned long long m, val = 0, mul = 1;
    int i = 0, numLen;
    char c;
    scanf("%c", &c);
    while ( (c <= '9') && (c >= '0') ) {
        num[i++] = CharToInt(c);
        scanf("%c", &c);
    }
    numLen = i;
    scanf("%llu", &m);
    for (int i = numLen - 1; i >= 0; i --) {
        val = (val + (mul * num[i]) % m) % m;
        mul = (mul * 10) % m;
    }
    printf("%llu", val);
    return 0;
}
