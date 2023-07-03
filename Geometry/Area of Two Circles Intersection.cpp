#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1.0);

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    long double x1, x2, y1, y2, r1, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    long double ans, d = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));

    if (r2 > r1) {
        swap(x1, x2);
        swap(y1, y2);
        swap(r1, r2);
    }

    if (d > (r1 + r2)) {
        ans = 0;
    }
    else if ((r1 >= r2) && d <= (r1 - r2)) {
        ans = (PI * r2 * r2);
    }
    else {
        long double t1 = 2 * acos((r1 * r1 + d * d - (r2 * r2)) / (2.0 * d * r1));
        long double t2 = 2 * acos((r2 * r2 + d * d - (r1 * r1)) / (2.0 * d * r2));
        ans = ((r1 * r1 * (t1 - sin(t1))) / 2.0) + ((r2 * r2 * (t2 - sin(t2))) / 2.0);
    }

    cout << setprecision(15);
    cout << ans << '\n';

    return 0;
}
