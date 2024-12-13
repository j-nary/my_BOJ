//BOJ_32931 자석 놀이 [실버 2]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
using ll = long long;

ll dp[2][200005];
ll card[2][200005];

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N; cin >> N;

  for (int i = 0; i < 2; i++)
    for (int j = 0; j < N; j++) cin >> card[i][j];
  
  dp[0][0] = card[0][0];
  dp[0][1] = card[0][1] + card[0][0];
  dp[1][0] = card[1][0] + card[0][0];
  dp[1][1] = max(dp[0][1], dp[1][0]) + card[1][1];

  for (int j = 2; j < N; j++) {
    dp[0][j] = dp[0][j - 1] + card[0][j];
    dp[1][j] = dp[1][j - 1] + card[1][j];

    if (card[0][j] > 0) {
      dp[0][j] += card[0][j];
      dp[0][j] = max(dp[0][j], dp[1][j]);
    }
    if (card[1][j] > 0) {
      dp[1][j] += card[1][j];
      dp[1][j] = max(dp[1][j], dp[0][j]);
    }
  }

  cout << dp[1][N - 1] << '\n';
}