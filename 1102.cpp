//BOJ_1102 발전소 [플래티넘 5]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int N, P;   //적어도 P개의 발전소가 고장나있지 않도록
int W[16][16];
bool power[16];
int dp[1 << 16];    //dp[i] : i 상태일 때 드는 최소비용

int promising(int s) {
    int cnt = 0;
    while (s != 0) {
        cnt += (s & 1);
        s = s >> 1;
    }
    return cnt >= P;
}

int Fix(int state) {
    if (promising(state)) return 0;

    int &ret = dp[state];
    if (ret != -1) return ret;

    ret = 1e9;
    for (int i = 0; i < N; i++) {
        // 고장나지 않은 i로 고장난 j 고치기
        if ((state & (1 << i)) == 0) continue;

        for (int j = 0; j < N; j++) {
            if ((state & (1 << j)) == 0) {  //고장났다면
                int nxt = state | (1 << j);
                ret = min(ret, W[i][j] + Fix(nxt));
            }
        }
    }
    if (ret == 1e9) return -1;
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    // 발전소 i를 이용해서 j를 재시작할 때 드는 비용
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> W[i][j];
        }
    }

    int state = 0;
    for (int i = 0; i < N; i++) {
        char ip; cin >> ip;
        if (ip == 'Y') state |= (1 << i);
    }
    cin >> P;

    memset(dp, -1, sizeof(dp));
    cout << Fix(state) << '\n';
}