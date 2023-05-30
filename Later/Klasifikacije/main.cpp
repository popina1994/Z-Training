#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define DEBUG 1

using namespace std;

struct Point {
    int x, y;
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    friend ostream& operator<<(ostream& out, const Point& p) {
        return out << "(" << p.x << ", " << p.y << ")";
    }
};

struct Vector {
    Point end;
    Vector(const Point& p1, const Point& p2) {
        end.x = p2.x - p1.x;
        end.y = p2.y - p1.y;
    }
    // cross product of two vectors in 2d
    int operator*(const Vector& v) const {
        return end.x * v.end.y - end.y * v.end.x;
    }

    // scalar product of two vectors in 2d
    int operator^(const Vector& v) const {
        return end.x * v.end.x + end.y * v.end.y;
    }

    int IntensitySquared() const {
        return end.x * end.x + end.y * end.y;
    }
};
struct Segment {

    Point begin, end;
    Segment(const Point& p1, const Point& p2) : begin(p1), end(p2) {}

    // returns true if p is on line determined by points begin and end
    bool OnLine(const Point& p) const {
        return (Vector(begin, end) * Vector( end, p) ) == 0;
    }

    // return true if lines determined by segments are parallel
    bool AreParallel(const Segment& s) const {
        return (Vector(begin, end) * Vector(s.begin, s.end)) == 0;
    }

    // return true if segments have length
    bool AreEqual(const Segment& s) const {
        return Vector(begin, end).IntensitySquared() == Vector(s.begin, s.end).IntensitySquared();
    }

    // return true if Segments intersect angle is 90 degrees
    bool RightAngle(const Segment& s) const {
        return (Vector(begin, end) ^ Vector(s.begin, s.end)) == 0;
    }

    friend ostream& operator<<(ostream& out, const Segment& s) {
        return out << "(" << s.begin << ", " << s.end << ")";
    }

};

void OutputSecondary(vector<const char*>& vSecondaryClass) {
    if (!vSecondaryClass.empty()) {
        printf(" - ");
        for (unsigned int idx = 0; idx < vSecondaryClass.size(); idx++) {
            printf("%s", vSecondaryClass[idx]);
            if (idx != vSecondaryClass.size() - 1)
                printf(", ");
        }
    }
}

int main() {
    if (DEBUG) {
        freopen("ulaz.in", "r", stdin);
        freopen("ulaz.out", "w", stdout);
    }
    int testCase;
    scanf("%d", &testCase);

    for (int cnt = 0; cnt < testCase; cnt++) {
        vector <Point> vPoint;
        vector <Segment> vSegment;
        vector <const char*> vSecondaryClass;
        int n;
        scanf("%d", &n);

        for (int idx = 0; idx < n; idx ++) {
            Point p;
            scanf("%d%d", &p.x, &p.y);
            vPoint.push_back(p);
        }
        vPoint.push_back(vPoint[0]);
        vSegment.push_back(Segment(vPoint[0], vPoint[1]));


        for (unsigned int idx = 2; idx < vPoint.size(); idx++)
            if (vSegment.back().OnLine(vPoint[idx]))
                vSegment.back().end = vPoint[idx];
            else
                vSegment.push_back( Segment(vSegment.back().end, vPoint[idx]) );

        switch (vSegment.size()) {
            case 1:
                printf("Duz");
                break;
            case 3:
                printf("Trougao");

                if (vSegment[0].AreEqual(vSegment[1]) || vSegment[1].AreEqual(vSegment[2]) ||
                        vSegment[0].AreEqual(vSegment[2]))
                    vSecondaryClass.push_back("Jednakokraki");

                if (vSegment[0].RightAngle(vSegment[1]) || vSegment[1].RightAngle(vSegment[2]) ||
                        vSegment[0].RightAngle(vSegment[2]))
                    vSecondaryClass.push_back("Pravougli");

                if (vSegment[0].AreEqual(vSegment[1]) && vSegment[1].AreEqual(vSegment[2]))
                    vSecondaryClass.push_back("Jednakostranicni");

                OutputSecondary(vSecondaryClass);
                break;
            case 4:
                printf("Cetvorougao");

                if (vSegment[0].AreParallel(vSegment[2]) && vSegment[1].AreParallel(vSegment[3]))
                    vSecondaryClass.push_back("Paralelogram");

                if (vSegment[0].AreEqual(vSegment[1]) && vSegment[1].AreEqual(vSegment[2]) &&
                    vSegment[2].AreEqual(vSegment[3]) && vSegment[3].AreEqual(vSegment[0]))
                    vSecondaryClass.push_back("Romb");

                if (vSegment[0].AreParallel(vSegment[2]) || vSegment[1].AreParallel(vSegment[3]))
                    vSecondaryClass.push_back("Trapez");

                if (vSegment[0].AreParallel(vSegment[2]) && vSegment[1].AreParallel(vSegment[3])
                    && vSegment[0].RightAngle(vSegment[1]))
                        vSecondaryClass.push_back("Pravougaonik");

                if (vSegment[0].AreEqual(vSegment[1]) && vSegment[1].AreEqual(vSegment[2]) &&
                    vSegment[2].AreEqual(vSegment[3]) && vSegment[3].AreEqual(vSegment[0])
                    && vSegment[0].RightAngle(vSegment[1]))
                    vSecondaryClass.push_back("Kvadrat");

                OutputSecondary(vSecondaryClass);
                break;
            default:
                printf("Ostalo");
        }
        printf("\n");
    }


    return 0;
}
