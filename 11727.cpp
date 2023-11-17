//BOJ_11727 2xn 타일링 2 [실버 3]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int dp[1003];
const int MOD = 10007;
int tile(int N) {
    if (dp[N]) return dp[N];
    if (N == 2) return dp[N] = 3;
    if (N == 1) return dp[N] = 1;

    return dp[N] = (2 * tile(N - 2) % MOD + tile(N - 1) % MOD) % MOD;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    cout << tile(N) << '\n';
}