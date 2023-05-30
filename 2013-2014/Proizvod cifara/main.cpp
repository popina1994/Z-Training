#include <iostream>
#include <cmath>
using namespace std;
int x[1000], length;

void loading(int n) {
    long long ng = n;
    length = 0;
    long root = ceil(sqrt(n));
    if (n == 0) {
        length = 2;
        x[0] = 1;
        x[1] = 0;
    } else
        for(int i = 9; i > 1; i--) {
            // prolazi po svim mogucim brojevima
            while (ng % i == 0) {
                ng /= i;
                x[length] = i;
                ++length;
            }
        }
    if (ng > 1) {
        length = -1;
    }
}

int main() {
    long long n;
    cin >> n;
    if (n == 1)
        cout << 1;
    else {
        loading(n);
        if (length == -1)
            cout << -1;
        else
            for (int i = length - 1; i >= 0; i--)
                cout << x[i];
    }
}
