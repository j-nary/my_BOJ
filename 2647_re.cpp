//BOJ_2647 검은점과 하얀점 연결 [플래티넘 3]
//PS 시험대비 다시 풀기

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool can[102][102];
int dp[102][102];
//dp[i][j] : i~j번째 돌을 사용했을 때의 거리 합의 최솟값
int h[102][102];
//h[i][j] : i~j번째 돌을 사용했을 때의 높이의 최댓값
vector<bool> rk;
int path[102][102];
int dpSolve(int s, int e) {
    if (s >= e) return 0;
    int& ret = dp[s][e];
    if (dp[s][e] != 0) return ret;

    ret = 1e9;
    for (int k = s + 1; k <= e; k++) {
        // if (can[s][k] == false) continue;
        int tmp = dpSolve(s + 1, k - 1) + dpSolve(k + 1, e) + (h[s + 1][k - 1] + 1) * 2 + (k - s);
        if (tmp < ret) {
            ret = tmp;
            h[s][e] = max(h[s + 1][k - 1] + 1, h[k + 1][e]);
            path[s][e] = k;
        }
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int input;
        scanf("%1d", &input);
        rk.push_back(input);
        if (i > 0 && rk[i] != rk[i - 1]) {
            dp[i-1][i] = 3;
        }
    }

    //i,j를 이을 수 있는 지 여부 저장
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int cnt = 0;
            for (int k = i; k <= j; k++) {
                if (rk[k] == 1) cnt += 1;
                else cnt -= 1;
            }

            if (!cnt) can[i][j] = false;
        }
    }

    cout << dpSolve(0, N - 1) << '\n';

}