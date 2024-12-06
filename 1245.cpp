//BOJ_1245 농장 관리 [골드 5]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

int MAP[102][102];
bool chk[102][102];
int dir[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
bool flag;

void bfs(int cr, int cc) {
  queue<pair<int, int>> q;
  q.push({cr, cc});

  int peak = MAP[cr][cc];
  chk[cr][cc] = true;

  while (!q.empty()) {
    auto [r, c] = q.front(); q.pop();
    
    for (int i = 0; i < 8; i++) {
      int nr = r + dir[i][0];
      int nc = c + dir[i][1];

      if (MAP[nr][nc] < 0) continue;
      if (MAP[nr][nc] > peak) flag = false;
      if (chk[nr][nc] || MAP[nr][nc] != peak) continue;
      chk[nr][nc] = true;
      q.push({nr, nc});
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N, M; cin >> N >> M;
  memset(MAP, -1, sizeof(MAP));
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++) cin >> MAP[i][j];

  int ans = 0;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      if (MAP[i][j] < 0 || chk[i][j]) continue;
      flag = true;
      bfs(i, j);
      if (flag) ans++;
    }
  }

  cout << ans << '\n';
}