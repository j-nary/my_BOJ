//BOJ_22862 가장 긴 짝수 연속한 부분 수열 (large)
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int N, K, ans;
vector<int> v;

void dfs(int idx, int cnt, int except) {
  if (idx == N || except == K) {
    ans = max(ans, cnt);
    return;
  }
  if (v[idx] % 2) dfs(idx + 1, cnt + 1, except);
  else if (except < K) dfs(idx + 1, cnt, except + 1);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  cin >> N >> K;
  v.resize(N);
  for (int i = 0; i < N; i++) cin >> v[i];

  for (int i = 0; i < N; i++) if (v[i] % 2) dfs(i, 1, 0);
  cout << ans << '\n';
}