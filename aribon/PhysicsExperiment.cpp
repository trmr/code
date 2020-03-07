#include <bits/stdc++.h>

using namespace std;

double pos_ball(int i, int h, int r, int t) {
    double g = 10.0;
    double t1 = sqrt(2.0 * (double)h / g);
    bool dir;

    if (t1 - t < 0) dir = true;
    else if (t1 > t && ((int)floor(t1 / t) % 2) == 0) dir = true;
    else if (t1 > t && ((int)floor(t1 / t) % 2) != 0) dir = false;

    if (dir) {
        double d = t - 
    }




}

int main() {
    int n, h, r, t;cin >> n >> h >> r >> t;

    double g = 10.0;


}