//BOJ_1513 경로찾기 [골드 2]

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[51][51][51][51];
//dp[r][c][오락실 최대번호][오락실 개수] 인 경우의 수
int orak[51][51];
int MOD = 1000007;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, M, C; cin >> N >> M >> C;
    for (int i = 1; i <= C; i++) {
        int r, c; cin >> r >> c;
        orak[r][c] = i;
    }

    if (orak[1][1] != 0) dp[1][1][orak[1][1]][1] = 1;
    else dp[1][1][0][0] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (i == 1 && j == 1) continue;
            int oNum = orak[i][j];
            //오락실이라면
            if (oNum != 0) {
                for (int k = 0; k < oNum; k++) {
                    for (int cnt = 0; cnt <= k; cnt++) {
                        dp[i][j][oNum][cnt + 1] += dp[i-1][j][k][cnt] + dp[i][j-1][k][cnt];
                        dp[i][j][oNum][cnt + 1] %= MOD;
                    }
                }
            }
            //오락실이 아니라면
            else {
                for (int k = 0; k <= C; k++) {
                    for (int cnt = 0; cnt <= k; cnt++) {
                        dp[i][j][k][cnt] += dp[i-1][j][k][cnt] + dp[i][j-1][k][cnt];
                        dp[i][j][k][cnt] %= MOD;
                    }
                }
            }
        }
    }

    for (int cnt = 0; cnt <= C; cnt++) {
        int sum = 0;
        for (int k = 0; k <= C; k++) {
            sum += dp[N][M][k][cnt];
            sum %= MOD;
        }
        cout << sum << " ";
    }
}