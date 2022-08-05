#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int home[1003][3];
int dp[1003][3];

int getD(int r, int c) {
    if (dp[r][c] != -1) return dp[r][c];

    if (c == 0)
        return dp[r][c] = home[r][c] + min(getD(r-1, 1), getD(r-1, 2));
    if (c == 1)
        return dp[r][c] = home[r][c] + min(getD(r-1, 0), getD(r-1, 2));
    if (c == 2)
        return dp[r][c] = home[r][c] + min(getD(r-1, 1), getD(r-1, 0));

}

int main() {
    int N; cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < 3; j++)
            cin >> home[i][j];

    memset(dp, -1, sizeof(dp));
    dp[0][0] = home[0][0];  //첫번째집은 빨간색
    dp[0][1] = 1001;
    dp[0][2] = 1001;
    int res = min(getD(N-1, 1), getD(N-1, 2));

    memset(dp, -1, sizeof(dp));
    dp[0][0] = 1001;        //첫번째집은 초록색
    dp[0][1] = home[0][1];
    dp[0][2] = 1001;
    int tmp = min(getD(N-1, 0), getD(N-1, 2));
    res = min(tmp, res);

    memset(dp, -1, sizeof(dp));
    dp[0][0] = 1001;        //첫번째집은 파란색
    dp[0][1] = 1001;
    dp[0][2] = home[0][2];
    tmp = min(getD(N-1, 0), getD(N-1, 1));
    res = min(tmp, res);

    cout << res << endl;
}