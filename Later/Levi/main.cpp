#include <iostream>
#include <cstdio>
#define DEBUG 1

using namespace std;

struct Point {
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
};

inline int Abs(int x) {
    return x > 0 ? x : -x;
}

Point Projection(const Point& p) {
    if ( (p.x >= 0) && (p.y <= 1) )
        return Point(0, -p.x + p.y);

    if ( (p.x >= -1) && (p.y > 1) )
        return Point(0, p.x + p.y);

    return Point(-(Abs(p.x) + Abs(p.y)), 0);

}


bool ProjectExist(const Point& p) {
    if ( (p.x == 0) && (p.y <= 0) )
        if ( (p.y % 4) == 0)
            return true;

    if ( (p.x == 0) && (p.y > 0) )
        if ( (p.y % 4) == 2)
            return true;

    if ( (p.x < 0) && (p.y == 0))
        if ( (p.x % 4) == 0)
            return true;
    return false;
}

int main() {
    if (DEBUG)
        freopen("ulaz.in", "r", stdin);
    int q;

    scanf("%d", &q);

    for (int cnt = 0; cnt < q; cnt++) {
        int x, y;
        scanf("%d%d", &x, &y);

        Point p(x, y);
        if (ProjectExist(Projection(p)))
            printf("DA\n");
        else
            printf("NE\n");
    }

    return 0;
}
