//BOJ_1513 경로 찾기 [골드 2]
//PS 시험대비 다시 풀기

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long dp[51][51][51][51];
//dp[r][c][방문한 오락실 개수][가장 최근에 방문한 오락실 번호]
int orak[51][51];
int PER = 1000007;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, M, C; cin >> N >> M >> C;
    for (int i = 1; i <= C; i++) {
        int r, c; cin >> r >> c;
        orak[r][c] = i;
    }

    if (orak[1][1] != 0) dp[1][1][1][orak[1][1]] = 1;
    else dp[1][1][0][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            //오락실이 있다면
            if (orak[i][j] != 0) {
                int oNum = orak[i][j];
                for (int k = 0; k < oNum; k++) {
                    for (int cnt = 0; cnt < oNum; cnt++) {
                        dp[i][j][cnt + 1][oNum] += dp[i-1][j][cnt][k] + dp[i][j-1][cnt][k];
                        dp[i][j][cnt + 1][oNum] %= PER;
                    }
                }
            }
            //오락실이 없다면
            else {
                for (int k = 0; k <=C; k++) {
                    for (int cnt = 0; cnt <= C; cnt++) {
                        dp[i][j][cnt][k] += dp[i-1][j][cnt][k] + dp[i][j-1][cnt][k];
                        dp[i][j][cnt][k] %= PER;
                    }
                }
            }
        }
    }

    for (int cnt = 0; cnt <= C; cnt++) {
        long long sum = 0;
        for (int k = 0; k <= C; k++) { 
            sum += dp[N][M][cnt][k];
            sum %= PER;
        }
        cout << sum << " ";
    }
    cout << '\n';
}