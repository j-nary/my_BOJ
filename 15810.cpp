//BOJ_15810 풍선 공장 [실버 2]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<int> bn;
    for (int i = 0; i < N; i++) {
        int input ;cin >> input;
        bn.push_back(input);
    }

    long long left = 0, right = 1e18;
    long long ans = 1e18;
    while(left <= right) {
        long long mid = (left + right) / 2;

        long long cnt = 0;
        for (int i = 0; i < N; i++) {
            cnt += (mid / bn[i]);
        }

        if (cnt >= M) {
            ans = min(ans, mid);
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << '\n';
}