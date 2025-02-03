//BOJ_1389 케빈 베이컨의 6단계 법칙 [실버 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<int> adj[102];
int dist[102][102];

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N, M;
  cin >> N >> M;
  
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) dist[i][j] = 1e9;
  }

  for (int i = 0; i < M; i++) {
    int A, B; cin >> A >> B;
    dist[A][B] = 1;
    dist[B][A] = 1;
  }

  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  vector<pair<int, int>> res;
  for (int i = 1; i <= N; i++) {
    int cnt = 0;
    for (int j = 1; j <= N; j++) {
      if (i == j) continue;
      cnt += dist[i][j];
    }
    res.push_back({cnt, i});
  }
  sort(res.begin(), res.end());
  cout << res[0].second << '\n';
}