#include <algorithm>
#include <iostream>
#include <complex>
#include <vector>
#include <limits>
#include <cmath>
using namespace std;
 
typedef long double gtype;
const gtype pi = M_PI;
typedef complex<gtype> point;
#define x real()
#define y imag()
#define polar(r, t) polar((gtype) (r), (t))
// vector
#define rot(v, t) ( (v) * polar(1, t) )
#define crs(a, b) ( (conj(a) * (b)).y )
#define dot(a, b) ( (conj(a) * (b)).x )
#define pntLinDist(a, b, p) ( abs(crs((b)-(a), (p)-(a)) / abs((b)-(a))) )
bool cmp_point(point const& p1, point const& p2) {
    return p1.x == p2.x ? (p1.y < p2.y) : (p1.x < p2.x);
}
 
// O(n.log(n)) - monotone chain
vector<point> mcH;
void monotoneChain(vector<point> &ps) {
    vector<point> p(ps.begin(), ps.end() - 1);
    int n = p.size(), k = 0;
    mcH = vector<point>(2 * n);
    sort(p.begin(), p.end(), cmp_point);
    for (int i = 0; i < n; i++) {
        while (k >= 2 && crs(mcH[k - 1] - mcH[k - 2], p[i] - mcH[k - 2]) <= 0)
            k--;
        mcH[k++] = p[i];
    }
    for (int i = n - 2, t = k + 1; i >= 0; i--) {
        while (k >= t && crs(mcH[k - 1] - mcH[k - 2], p[i] - mcH[k - 2]) <= 0)
            k--;
        mcH[k++] = p[i];
    }
    mcH.resize(k);
}
// O(n) - rotating calipers (works on a ccw closed convex hull)
gtype rotatingCalipers(vector<point> &ps) {
    int aI = 0, bI = 0;
    for (size_t i = 1; i < ps.size(); ++i)
        aI = (ps[i].y < ps[aI].y ? i : aI), bI = (ps[i].y > ps[bI].y ? i : bI);
    gtype minWidth = ps[bI].y - ps[aI].y, aAng, bAng;
    point aV = point(1, 0), bV = point(-1, 0);
    for (gtype ang = 0; ang < pi; ang += min(aAng, bAng)) {
        aAng = acos(dot(ps[aI + 1] - ps[aI], aV)
            / abs(aV) / abs(ps[aI + 1] - ps[aI]));
        bAng = acos(dot(ps[bI + 1] - ps[bI], bV)
            / abs(bV) / abs(ps[bI + 1] - ps[bI]));
        aV = rot(aV, min(aAng, bAng)), bV = rot(bV, min(aAng, bAng));
        if (aAng < bAng)
            minWidth = min(minWidth, pntLinDist(ps[aI], ps[aI] + aV, ps[bI]))
            , aI = (aI + 1) % (ps.size() - 1);
        else
            minWidth = min(minWidth, pntLinDist(ps[bI], ps[bI] + bV, ps[aI]))
            , bI = (bI + 1) % (ps.size() - 1);
    }
    return minWidth;
}
 
int main() {
    int caseI = 0, n;
    vector<point> p;
    cout.precision(2);
    while (cin >> n && n) {
        p.clear(), p.resize(n + 1);
        // input
        for (int i = 0; i < n; ++i)
            cin >> p[i].x >> p[i].y;
        p[n] = p[0];
        // solve
        monotoneChain(p);
        if (caseI)
            cout << endl;
        cout << "Case " << ++caseI << ": " << fixed << rotatingCalipers(mcH);
    }
    return 0;
}