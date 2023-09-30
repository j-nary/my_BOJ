//BOJ_26072 곰곰이와 시소 [실버 2]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, L; cin >> N >> L;
    vector<pair<double, double>> ss;
    for (int i = 0; i < N; i++) {
        double x; cin >> x;
        ss.push_back({x, 0});
    }
    for (int i = 0; i < N; i++) {
        double w; cin >> w;
        ss[i].second = w;
    }

    double left = 0, right = N;
    double ans = 0;
    for (int i = 0; i < 10000; i++) {
        double mid = (left + right) / 2;
        double lw = 0, rw = 0;
        for (int i = 0; i < N; i++) {
            if (ss[i].first > mid) rw += ss[i].second;
            else lw += ss[i].second;
        }
        if (rw - lw <= 1e-6) {
            left = mid;
            ans = mid;
        } else {
            right = mid;
        }
    }
    printf("%.10lf\n", left);
}