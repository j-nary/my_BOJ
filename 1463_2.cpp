//BOJ_1463 1로 만들기 [실버 3]
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[1000006];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;

    dp[1] = 0;
    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i-1] + 1;
        if (i%3 == 0) {
            dp[i] = min(dp[i], dp[i/3] + 1);
        }
        if (i%2 == 0) {
            dp[i] = min(dp[i], dp[i/2] + 1);
        }
    }

    cout << dp[N] << '\n';
}