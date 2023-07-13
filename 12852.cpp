//BOJ_12852 1로 만들기 2
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int dp[1000006];
int path[1000006];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    fill(&dp[0], &dp[1000006], 1e9);
    dp[1] = 0;
    dp[2] = dp[3] = 1;  
    path[2] = path[3] = 1;

    for (int i = 4; i <= N; i++) {
        if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
            dp[i] = dp[i / 3] + 1;
            path[i] = i / 3;
        }

        if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
            dp[i] = dp[i / 2] + 1;
            path[i] = i / 2;
        }

        if (dp[i] > dp[i - 1] + 1) {
            dp[i] = dp[i - 1] + 1;
            path[i] = i - 1;
        }
    }

    cout << dp[N] << '\n';

    while(1) {
        cout << N << " ";
        if (N == 1) break;
        N = path[N];
    }
    cout << '\n';
}