//BOJ_13904 과제 [골드 3]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int Assignment[1003];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    vector<pair<int, int>> v;
    for (int i = 0; i < N; i++) {
        int d, w; cin >> d >> w;
        v.push_back({w, d});
    }
    sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
    });

    for (int i = 0; i < N; i++) {
        int day = v[i].second;
        if (!Assignment[day]) Assignment[day] = v[i].first;
        else {
            while (Assignment[day]) {
                day--;
                if (day < 0) break;
                if (!Assignment[day]) {
                    Assignment[day] = v[i].first;
                    break;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i < 1001; i++) {
        ans += Assignment[i];
    }
    cout << ans << '\n';
}