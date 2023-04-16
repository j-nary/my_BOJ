//BOJ_4883 삼각그래프 [실버 1]
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int dp[100005][3];
int v[100005][3];
int solve(int N) {
    // memset(dp, 0, sizeof(dp));
    // memset(v, 0, sizeof(v));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> v[i][j];
            dp[i][j] = v[i][j];
        }
    }

    dp[0][2] += dp[0][1];
    dp[0][0] = 1e9;
    for (int i = 1; i < N; i++) {
        dp[i][0] += min(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] += min({dp[i-1][0], dp[i-1][1], dp[i-1][2], dp[i][0]});
        dp[i][2] += min({dp[i-1][1], dp[i-1][2], dp[i][1]});
    }
    return dp[N - 1][1];
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int cnt = 1;
    while (1) {
        int N; cin >> N;
        if (N == 0) return 0;
        cout << cnt << ". " << solve(N) << '\n';
    }
}