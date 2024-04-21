//BOJ_1946 신입 사원 [실버 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void test_case() {
    int N; cin >> N;
    vector<pair<int, int>> v;
    for (int i = 1; i <= N; i++) {
        int a, b; cin >> a >> b;
        v.push_back({b, a});
    }

    sort(v.begin(), v.end());
    int ans = 1;
    int idx = 0;
    for (int i = 1; i < N; i++) {
        if (v[idx].second > v[i].second) {
            ans++;
            idx = i;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        test_case();
    }
}


// 1 5 1
// 2 3 2
// 3 4 3
// 4 2 4
// 5 1 5

// 5 1 5
// 4 2 4
// 2 3 2
// 3 4 3
// 1 5 1