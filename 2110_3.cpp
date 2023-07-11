//BOJ_2110 공유기 설치 [골드 4]
//4개월만에 재도전 !
//가장 인접한 두 공유기 사이의 최대 거리
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int N, C;
vector<int> H;

bool promising(int dist) {
    int cnt = 0;
    int tmp = H[0];
    for (int i = 1; i < N; i++) {
        if (H[i] - tmp >= dist) {
            cnt++;
            tmp = H[i];
        }
    }
    return cnt >= C;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        int input; cin >> input;
        H.push_back(input);
    }
    sort(H.begin(), H.end());

    int left = 0, right = H[N-1] - H[0];
    int ans = 0;
    while(left <= right) {
        int mid = (left + right) / 2;

        if (promising(mid)) {
            left = mid + 1;
            ans = max(ans, mid);
        } else {
            right = mid - 1;
        }
    }
    cout << ans << '\n';
}