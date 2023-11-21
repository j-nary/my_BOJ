//BOJ_2098 외판원 순회 [골드 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int N, W[17][17];
int dp[17][1 << 17];

int TSP(int cur, int visited) {
    int &ret = dp[cur][visited];
    if (ret != 0) return ret;

    //base case : 모든 마을 방문
    if (visited == (1 << N) - 1) {
        if (W[cur][0] != 0) return W[cur][0];
        return 1e9;
    }

    ret = 1e9;
    for (int i = 0; i < N; i++) {
        if (visited & (1 << i)) continue;   //이미 방문
        if (W[cur][i] == 0) continue;   //경로 없음
        ret = min(ret, TSP(i, visited | (1 << i)) + W[cur][i]);
    }

    return ret;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> W[i][j];
        }
    }

    cout << TSP(0, 1) << '\n';
}