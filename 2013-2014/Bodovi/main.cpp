#include <iostream>
#include <cstdio>

using namespace std;

const int nmax = 1e9;

int n, b, sol;

int main()
{
    scanf("%d%d", &n, &b);
    sol = n - b%3 - b/3;
    printf("%d", sol);
    return 0;
}
