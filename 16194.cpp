//BOJ_16194 카드 구매하기 2 [실버 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int price[1003];
int dp[1003];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    vector<int> pack;
    for (int i = 1; i <= N; i++) {
        cin >> price[i];
    }

    dp[1] = price[1];
    for (int i = 2; i <= N; i++) {
        dp[i] = 1e9;
        for (int j = 1; j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j] + price[j]);
        }
    }
    cout << dp[N] << '\n';
}