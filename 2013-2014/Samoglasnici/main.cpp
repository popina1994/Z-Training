#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int length_max = 250;

int main() {
    int counter = 0;
    char tempc;
    freopen("in.in", "r", stdin);
    while(scanf("%c", &tempc) == 1)
        if (tempc == 'a' || tempc == 'e' || tempc == 'i' || tempc == 'o' || tempc == 'u')
            counter++;
    freopen("out.out", "w", stdout);
    printf("%d", counter);
    return 0;
}
