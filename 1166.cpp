//BOJ_1166 선물 [실버 3]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, L, W, H;
    cin >> N >> L >> W >> H;

    double left = 0, right = max({L, W, H});
    double ans = 0;
    double square = L * W * H;
    for (int i = 0; i < 101010; i++) {
        double mid = (left + right) / 2;
        ll s = (ll)(L / mid) * (ll)(W / mid) * (ll)(H / mid);
        if (s < N) {
            right = mid;
        } else {
            ans = max(ans, mid);
            left = mid;
        }
    }

    printf("%.10lf\n", ans);
}