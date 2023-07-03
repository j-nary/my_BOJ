//BOJ_11051 이항 계수 2 [실버 2]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
const int MOD = 10007;

int dp[1002][1002];
int combi(int N, int K) {
    if (dp[N][K] != 0) return dp[N][K];
    if (K == 1) return dp[N][K] = N % MOD;
    else if (K == 0) return dp[N][K] = 1 % MOD;
    else if (N == K) return dp[N][K] = 1 % MOD;
    return dp[N][K] = (combi(N-1, K-1) % MOD + combi(N-1, K) % MOD) % MOD;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, K; cin >> N >> K;
    cout << combi(N, K) << '\n';
}