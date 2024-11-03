//BOJ_12026 BOJ 거리 [실버 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int N;
string ip;
vector<int> Block[3];
int dp[1003];
//dp[i] : i번까지 오는데 필요한 에너지 양의 최솟값

// int DP(int idx) {
//   if (idx == 1) return dp[1] = 0;
//   if (dp[idx] != -1) return dp[idx];

//   int ret = 1e9;
  
//   vector<int> B;
//   switch(ip[idx - 1]) {
//     case 'B':
//       B = Block[2];
//       break;
//     case 'O':
//       B = Block[0];
//       break;
//     case 'J':
//       B = Block[1];
//       break;
//   }

//   for (int i = B.size() - 1; i >= 0; i--) {
//     if (B[i] > idx) continue;
//     ret = min(ret, DP(B[i]) + (idx - B[i]) * (idx - B[i]));
//   }
//   return ret;
// }
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  cin >> N >> ip;
  for (int i = 0; i < N; i++) {
    switch(ip[i]) {
      case 'B':
        Block[0].push_back(i + 1);
        break;
      case 'O':
        Block[1].push_back(i + 1);
        break;
      case 'J':
        Block[2].push_back(i + 1);
        break;
    }
  }

  fill(&dp[0], &dp[0] + 1003, 1e9);

  dp[1] = 0;
  for (int i = 1; i <= N; i++) {
    vector<int> B;
    switch(ip[i - 1]) {
      case 'B':
        B = Block[1];
        break;
      case 'O':
        B = Block[2];
        break;
      case 'J':
        B = Block[0];
        break;
    }

    for (int j = B.size() - 1; j >= 0; j--) {
      if (B[j] < i) continue;
      dp[B[j]] = min(dp[B[j]], dp[i] + (B[j]- i) * (B[j]- i));
    }
  }
  if (dp[N] == 1e9) cout << -1 << '\n';
  else cout << dp[N] << '\n';
}