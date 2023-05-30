#include <iostream>
#include <cstdio>


using namespace std;

int main() {
    int z, r;

    cin >> z >> r;

    int a = ( z + r ) / 2, b = (z - a);

    cout << a << " " << b;

    return 0;
}
