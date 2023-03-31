//BOJ_2166 다각형의 면적 [골드 5]
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

vector<pair<double, double>> dot;

double ccw(double x1, double y1, double x2, double y2, double x3, double y3) {
    return ((x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1)) / 2;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;
    double x, y;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        dot.push_back({x, y});
    }

    double res = 0;
    for (int i = 2; i < N; i++) {
        res += ccw(dot[0].first, dot[0].second, dot[i - 1].first, dot[i - 1].second, dot[i].first, dot[i].second);
    }

    printf("%.1lf\n", abs(res));
}