#include <iostream>
#include <cstdio>
#include <set>
#define DEBUG 0

using namespace std;

const int NUM_TEST = 3, MAX_NUM = 1000;
int n;

int main() {
    if (DEBUG)
        freopen("ulaz.in", "r", stdin);

    for (int idxTest = 0; idxTest < NUM_TEST; idxTest++) {
        set <int> s;

        cin >> n;
        for (int idx = 0; idx < n; idx ++) {
            int tmp;
            cin >> tmp;
            s.insert(tmp);
        }
        if (s.size() % 2 == 0)
            cout << 2;
        else cout << 1;
        cout << endl;
    }



    return 0;
}
