#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int nmax = 1e3;

struct tacka {
    double x, y;
};


int n;
double a, b, c, t[nmax];
// t oznacava rastojanje tacaka od prave

double distance(double a, double b, double c, tacka p) {
    return((a*p.x+b*p.y+c)/sqrt(a*a+b*b));
}

int main() {
    int tb;
    scanf("%d%lf%d%lf", &n, &a, &tb, &c);
    b = tb;
    for (int i = 0; i < n; i++) {
        tacka p;
        scanf("%lf%lf", &p.x, &p.y);
        t[i] = distance(a, b, c, p);
    }
    sort(t, t + n);
    double  dmid;
    dmid = (t[n/2] + t[n/2 - 1])/2;
    double sola, solb, solc;
    if (tb == 0) {
        solb = 0;
        solc =-c/a+dmid;
        sola = 1;
    } else {
        double k, n, y0, x0;
        k = -a/b; // prava je paralelna sa trazenom
        solb = 1; // b moze biti koliko hoce
        y0 = (dmid*sqrt(a*a+b*b) - c)/ b; x0 = 0;
        n = y0; //y0=0x+n-> n = y0
        sola = -k; // kada predje ponovo na desnu stranu
        solc = -n;
    }
    printf ("%.2lf %.2lf %.2lf", sola, solb, solc);
    return 0;
}
