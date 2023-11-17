//BOJ_11052 카드 구매하기 [실버 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int P[1003];
int dp[1003];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> P[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] = max(dp[i], dp[i - j] + P[j]);
        }
    }

    cout << dp[N] << '\n';
}

// 1 2 3 4
// 1 2 3 4
// 1 5 6 10
// 1 5 6 10
// 1 5 6 10