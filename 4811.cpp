//BOJ_4811 알약 [골드 5]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
using ll = unsigned long long;

ll dp[31][31];

ll dfs(int W, int H) {
  if (dp[W][H]) return dp[W][H];
  if (H == 0) return dp[W][H] = 1;

  ll ret = 0;
  if (W - 1 >= H) ret = dfs(W - 1, H);
  if (H - 1 >= 0) ret += dfs(W, H - 1);

  return dp[W][H] = ret;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  while(1) {
    int N; cin >> N;
    if (!N) break;
    cout << dfs(N, N) << '\n';
  }
}
