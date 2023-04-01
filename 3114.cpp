//BOJ_3114 사과와 바나나 [골드 2]
//DP로 풀기
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int appMap[1502][1502];
int banMap[1502][1502];
int dp[1502][1502];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    //입력 받기
    int R, C; cin >> R >> C;
    string input;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> input;
            if (input[0] == 'A') {
                input.erase(input.begin());
                appMap[i][j] = stoi(input);
            } else {
                input.erase(input.begin());
                banMap[i][j] = stoi(input);
            }
        }
    }

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            banMap[i][j] = banMap[i - 1][j] + banMap[i][j];
            appMap[i][j] = appMap[i - 1][j] + appMap[i][j];            
        }
    }

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (i == 1 && j == 1) {
                dp[1][1] = appMap[R][1] - appMap[1][1];
            }
            int sum = banMap[i-1][j] + (appMap[R][j] - appMap[i][j]);

            //왼쪽에서 오는 거
            if (j != 1) dp[i][j] = dp[i][j - 1] + sum;

            //대각선에서 오는 거
            int tmp = 0;
            if (j != 1) tmp = dp[i - 1][j - 1] + sum;
            dp[i][j] = max(dp[i][j], tmp);

            //위쪽에서 오는 거
            tmp = dp[i - 1][j] - (appMap[i][j] - appMap[i - 1][j]);
            dp[i][j] = max(dp[i][j], tmp);
        }
    }

    cout << dp[R][C] << '\n';
}