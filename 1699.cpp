//BOJ_1699 제곱수의 합 [실버 2]
#include <bits/stdc++.h>
#include <iostream>
#include <cmath>

using namespace std;

int dp[100005];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    dp[1] = 1, dp[2] = 2, dp[3] = 3;
    int tmp = 0;
    for (int i = 4; i <= N; i++) {
        long long a= sqrt(i);
        if (a * a == i) {   //제곱근인 경우
            dp[i] = 1;
            tmp = i;
        } else {
            dp[i] = 1e9;
            for (int j = 0; j * j < i; j++) {
                dp[i] = min(dp[i], dp[i - j*j] + 1);
            }
        }
    }

    cout << dp[N] << '\n';
}