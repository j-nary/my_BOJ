//BOJ_17182 우주 탐사선 [골드 3]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int N, K, ans = INT_MAX;
bool chk[12];
int adj[12][12];

void backtracking(int idx, int dist, int cnt) {
  if (cnt == N) {
    ans = min(ans, dist);
    return;
  }

  for (int i = 0; i < N; i++) {
    if (chk[i]) continue;
    chk[i] = true;
    backtracking(i, dist + adj[idx][i], cnt + 1);
    chk[i] = false;
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  cin >> N >> K;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) cin >> adj[i][j];

  // 플로이드 워셜
  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
      }
    }
  }
  
  chk[K] = true;
  backtracking(K, 0, 1);
  cout << ans << '\n';
}