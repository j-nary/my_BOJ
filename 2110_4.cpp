//BOJ_2110 공유기 설치 [골드 4]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<int> H;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, C; cin >> N >> C;
    for (int i = 0; i < N; i++) {
        int ip; cin >> ip;
        H.push_back(ip);
    }
    sort(H.begin(), H.end());
    //설치된 공유기의 간격으로 결정
    int left = 0, right = H[N - 1], mid = 0;
    int ans = 0;
    while (left <= right) {
        mid = (left + right) / 2;

        int cnt = 1;
        int idx = H[0];
        for (int i = 1; i < N; i++) {
            if (idx + mid <= H[i]) {
                cnt++;
                idx = H[i];
            }
        }

        if (cnt >= C) {
            left = mid + 1;
            ans = max(ans, mid);
        }
        else right = mid - 1;
    }

    cout << ans << '\n';
}