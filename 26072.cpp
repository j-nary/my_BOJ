//BOJ_26072 곰곰이와 시소 [실버 2]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, L; cin >> N >> L;
    vector<pair<double, double>> ss;    //{위치, 무게}
    for (int i = 0; i < N; i++) {
        double x; cin >> x;
        ss.push_back({x, 0});
    }
    for (int i = 0; i < N; i++) {
        double w; cin >> w;
        ss[i].second = w;
    }
    sort(ss.begin(), ss.end());

    double left = 0, right = L;
    double ans = 0;
    for (int i = 0; i < 1010; i++) {
        double mid = (left + right) / 2;
        double lw = 0, rw = 0;
        for (int i = 0; i < N; i++) {
            if (ss[i].first > mid) rw += (ss[i].first - mid) * ss[i].second;
            else lw += (mid - ss[i].first) * ss[i].second;
        }
        if (lw - rw <= 0) {
            left = mid;
        } else {
            right = mid;
        }
    }
    printf("%.10lf\n", left);
}