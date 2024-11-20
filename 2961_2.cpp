//BOJ_2961 도영이가 만든 맛있는 음식 [실버 2]

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int N, S, B, ans = 1e9;
vector<pair<int, int>> dish(11);

void dfs(int idx, int sour, int bitt) {
  if (idx == N) {
    if (bitt) ans = min(ans, abs(sour - bitt));
    return;
  }

  dfs(idx + 1, sour, bitt);
  dfs(idx + 1, sour * dish[idx].first, bitt + dish[idx].second);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> dish[i].first >> dish[i].second;
  dfs(0, 1, 0);
  cout << ans << '\n';
}