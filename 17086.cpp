//BOJ_17086 아기 상어 2 [실버 2]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

int G[52][52];
int dir[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

struct node { int r, c, d; };

int BFS(int cr, int cc) {
  bool chk[52][52];
  memset(chk, false, sizeof(chk));

  queue<node> q;
  q.push({cr, cc, 0});
  chk[cr][cc] = true;

  while (!q.empty()) {
    auto [r, c, d] = q.front(); q.pop();

    if (G[r][c] == 1) return d;

    for (int i = 0; i < 8; i++) {
      int nr = r + dir[i][0];
      int nc = c + dir[i][1];

      if (chk[nr][nc] || G[nr][nc] == -1) continue;

      chk[nr][nc] = true;
      q.push({nr, nc, d + 1});
    }
  }

  return 0;
}
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N, M; cin >> N >> M;
  memset(G, -1, sizeof(G));
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) cin >> G[i][j];
  }

  int ans = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      if (G[i][j] == 0) ans = max(ans, BFS(i, j));
    }
  }

  cout << ans << '\n';
}