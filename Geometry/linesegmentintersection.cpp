#include <bits/stdc++.h>
using namespace std;

long long orientation(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
    long long val = (x3 - x2) * (y2 - y1) - (x2 - x1) * (y3 - y2);
    if (val < 0) {
        return 1;
    } else if (val > 0) {
        return 2;
    }
    return 0;
}
bool onSegment(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
    return (x3 <= max(x1, x2) and x3 >= min(x1, x2) and y3 <= max(y1, y2) and y3 >= min(y1, y2));
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        long long x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        long long o1 = orientation(x1, y1, x2, y2, x3, y3);
        long long o2 = orientation(x1, y1, x2, y2, x4, y4);
        long long o3 = orientation(x3, y3, x4, y4, x1, y1);
        long long o4 = orientation(x3, y3, x4, y4, x2, y2);
        if (o1 != o2 and o3 != o4) {
            cout << "YES" << endl;
        } else if (o1 == 0 and onSegment(x1, y1, x2, y2, x3, y3))
            cout << "YES" << endl;
        else if (o2 == 0 and onSegment(x1, y1, x2, y2, x4, y4))
            cout << "YES" << endl;
        else if (o3 == 0 and onSegment(x3, y3, x4, y4, x1, y1))
            cout << "YES" << endl;
        else if (o4 == 0 and onSegment(x3, y3, x4, y4, x2, y2))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}