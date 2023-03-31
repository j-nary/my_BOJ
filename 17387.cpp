//BOJ_17387 선분 교차2 [골드 2]
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

pair<long long, long long> dot[4];

int ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
    long long cal = ((x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1));
    if (cal == 0) return 0;
    else if (cal < 0) return -1;
    else return 1;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    long long x, y;
    for (int i = 0; i < 4; i++) {
        cin >> x >> y;
        dot[i] = make_pair(x, y);
    }

    //한 점에서 만나는 경우
    for (int i = 0; i < 2; i++) {
        for (int j = 2; j < 4; j++) {
            if (dot[i].first == dot[j].first && dot[i].second == dot[j].second) {
                cout << 1 << '\n';
                return 0;
            }
        }
    }
    int a1 = ccw(dot[0].first, dot[0].second, dot[1].first, dot[1].second, dot[2].first, dot[2].second);
    int a2 = ccw(dot[0].first, dot[0].second, dot[1].first, dot[1].second, dot[3].first, dot[3].second);
    int b1 = ccw(dot[2].first, dot[2].second, dot[3].first, dot[3].second, dot[0].first, dot[0].second);
    int b2 = ccw(dot[2].first, dot[2].second, dot[3].first, dot[3].second, dot[1].first, dot[1].second);

    //네 점이 모두 평행한 경우
    if (a1 == 0 && a2 == 0 && b1 == 0 && b2 == 0) {
        int min1, min2, max1, max2;
        //y축에 평행할 때
        if (dot[0].first == dot[1].first && dot[1].first == dot[2].first && dot[2].first == dot[3].first) {
            min1 = min(dot[0].second, dot[1].second);
            min2 = min(dot[2].second, dot[3].second);
            max1 = max(dot[0].second, dot[1].second);
            max2 = max(dot[2].second, dot[3].second);
            if (!(max1 < min2 || max2 < min1)) {
                cout << 1 << '\n';
                return 0;
            }
        } else {
            min1 = min(dot[0].first, dot[1].first);
            min2 = min(dot[2].first, dot[3].first);
            max1 = max(dot[0].first, dot[1].first);
            max2 = max(dot[2].first, dot[3].first);
            if (!(max1 < min2 || max2 < min1)) {
                cout << 1 << '\n';
                return 0;
            }

        }
        cout << 0 << '\n';
    } else if (a1 * a2 <= 0 && b1 * b2 <= 0) cout << 1 << '\n';
    else cout << 0 << '\n';
}