//BOJ_1513 경로 찾기 [골드 2]
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int PER = 1000007;
int dp[51][51][51][51];
//dp[i][j][오락실 총 방문 횟수][방문한 오락실 최대 번호]
map<pair<int, int>, int> orak;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    //입력 받기
    int N, M, C; cin >> N >> M >> C;
    int cx, cy;
    for (int i = 1; i <= C; i++) {
        cin >> cx >> cy;
        orak.insert({{cx, cy}, i});
    }

    //초기값
    if (orak.find({1, 1}) != orak.end()) {
        int o = orak.find({1,1}) -> second;
        dp[1][1][1][o] = 1;
    } else {
        dp[1][1][0][0] = 1;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == 1 && j == 1) continue;
            
            //오락실이 있는 경우
            if (orak.find({i, j}) != orak.end()) {
                int oNum = orak.find({i, j}) -> second;
                for (int p = 0; p <= N; p++) {
                    for (int q = 0; q <= M; q++) {
                        dp[i][j][p + 1][oNum] = dp[i-1][j][p][q] + dp[i][j-1][p][q];

                        cout << "dp[" << i << "][" << j << "][" << p << " + 1][" << oNum << "] = " << dp[i][j][p+1][oNum] << '\n';
                    }
                }
            }

            //오락실이 없는 경우
            else {
                for (int p = 1; p <= N; p++) {
                    for (int q= 1; q <= N; q++) {
                        dp[i][j][p][q] = (dp[i-1][j][p][q] + dp[i][j-1][p][q]) % PER;
                        cout << "dp[" << i << "][" << j << "][" << p << "][" << q << "] = " << dp[i][j][p][q] << '\n';
                    }
                }
            }
        }
    }

    for (int p = 0; p <= N; p++) {
        int sum = 0;
        for (int q = 0; q <= N; q++) {
            sum += dp[N][M][p][q];
        }
        cout << sum << " ";
    }
    cout << '\n';
}