#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int fibonaci_n(int n) {
    int a = 0, b = 1, c, counter = 3;
    if (n == 1)
        return a;
    if (n == 2)
        return b;
    for (int counter = 2; counter < n; counter++){
        c = a + b;
        a = b;
        b = c;
    }
    return b;

}

int main() {
    int n;
    freopen("in.in", "r", stdin);
    scanf("%d", &n);
    freopen("out.out", "w", stdout);
    printf("%d", fibonaci_n(n));

    return 0;
}
