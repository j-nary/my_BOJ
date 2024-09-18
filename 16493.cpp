//BOJ_16493 최대 페이지 수 [실버 2]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int N, M;
vector<pair<int, int>> v;
int dp[302][2];
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int day, page;
    cin >> day >> page;
    if (day <= N) v.push_back({day, page});
  }
  if (v.empty()) {
    cout << "0\n";
    return 0;
  }

  int ans = 0;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j <= N; j++) {
      dp[j][i % 2] = dp[j][(i - 1) % 2];
      if (j - v[i].first >= 0) {
        dp[j][i % 2] = max(dp[j][i % 2], dp[j - v[i].first][(i - 1) % 2] + v[i].second);
        ans = max(ans, dp[j][i % 2]);
      }
    }
  }

  cout << ans << '\n';
}