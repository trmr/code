#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>

#define FOR(i, n) for(int (i)=0; (i)<(n); (i)++)

typedef long long ll;

using namespace std;

int N;
ll X[51], Y[51];

double ret;

void get_radius(double x, double y) {
    double r = 0;
    FOR(i, N) r = max(r, hypot(X[i]-x, Y[i]-y));
    ret = min(ret, r);
}

int main() {
    cin >> N;
    FOR(i, N) cin >> X[i] >> Y[i];
    ret = 1e9;

    FOR(z, N) FOR(y, z) {
        double rx = (X[y] + X[z])/2.0;
        double ry = (Y[y] + Y[z])/2.0;
        get_radius(rx, ry);

        FOR(x, y) {
            double a=hypot(X[y]-X[z], Y[y]-Y[z]);
            double b=hypot(X[z]-X[x], Y[z]-Y[x]);
            double c=hypot(X[x]-X[y], Y[x]-Y[y]);

            if(abs(a+b-c)<1e-9) continue;
            if(abs(a+c-b)<1e-9) continue;
            if(abs(c+b-a)<1e-9) continue;

            double rx=(a*a*(b*b+c*c-a*a)*X[x]+b*b*(a*a+c*c-b*b)*X[y]+c*c*(b*b+a*a-c*c)*X[z])/(a*a*(b*b+c*c-a*a)+b*b*(a*a+c*c-b*b)+c*c*(b*b+a*a-c*c));
			double ry=(a*a*(b*b+c*c-a*a)*Y[x]+b*b*(a*a+c*c-b*b)*Y[y]+c*c*(b*b+a*a-c*c)*Y[z])/(a*a*(b*b+c*c-a*a)+b*b*(a*a+c*c-b*b)+c*c*(b*b+a*a-c*c));
            get_radius(rx, ry);
        }
    }
    printf("%.12lf\n", ret);
}
