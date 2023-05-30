#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;

const int n_max = 1000;


struct timesegment {
    int w, flag;
    timesegment(int tw = 0, int tflag = 0) : w(tw), flag(tflag) {}
    void set(int h, int m, int s, int tflag) {
        w = 3600 * h + 60 * m + s;
        flag = tflag;
    }
    bool operator<(const timesegment &t) const {
        return (w < t.w || (w == t.w && flag < t.flag));
    }
};


int n;
timesegment t[2 * n_max];

int main() {
    int h, m, s, flag = -1, maxnumber = 0, currnumber = 0;
    timesegment temp;
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; i++) {
        scanf("%d:%d:%d", &h, &m, &s);
        t[i].set(h, m, s, flag);
        flag = -flag;
    }
    sort(t, t + 2 * n );
    for (int i = 0; i < 2 * n - 1; i++)
        if (t[i].flag == -1) {
            currnumber ++;
            if (currnumber > maxnumber)
                maxnumber = currnumber;
        } else currnumber --;
    printf("%d", maxnumber);
    return 0;
}
