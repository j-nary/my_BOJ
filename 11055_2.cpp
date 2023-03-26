//BOJ_11055 가장 큰 증가하는 부분 수열 [실버 2]
//8개월만에 재도전!
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

vector<int> input;
int dp[2][1000006];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;
    int maxSum = 0;
    for (int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        input.push_back(tmp);
        maxSum += tmp;
    }

    memset(dp, -1, sizeof(dp));
    dp[0][input[0]] = input[0];
    dp[0][0] = 0;
    int res = input[0];
    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= maxSum; j++) {
            dp[i % 2][j] = dp[(i - 1) % 2][j];
            if (j-input[i] < 0 || dp[(i - 1) % 2][j - input[i]] == -1) continue;
            if (dp[(i-1) % 2][j - input[i]] < input[i]) {
                dp[i % 2][j] = min(dp[i % 2][j], input[i]);
                if (dp[i % 2][j] == -1) dp[i % 2][j] = input[i];
                res = max(res, j);
            }
        }
    }
    cout << res << '\n';
}