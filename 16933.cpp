//BOJ_16933 벽 부수고 이동하기 3 [골드 1]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

int N, M, K;
int Map[1003][1003];
bool chk[1003][1003][11][2];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
struct node {
  int r, c, d, broken;
  bool tFlag;
};
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  cin >> N >> M >> K;
  memset(Map, -1, sizeof(Map));
  for (int i = 1; i <= N; i++) {
    string str; cin >> str;
    for (int j = 1; j <= M; j++) {
      Map[i][j] = str[j - 1] - '0';
    }
  }

  queue<node> q;
  q.push({1, 1, 1, 0, 1});
  int ans = 1e9;
  chk[1][1][0][1] = true;
  while (!q.empty()) {
    auto [r, c, d, broken, tFlag] = q.front();
    q.pop();

    if (r == N && c == M) {
      ans = min(ans, d);
      continue;
    }

    for (int i = 0; i < 4; i++) {
      int nr = r + dir[i][0];
      int nc = c + dir[i][1];

      if (Map[nr][nc] == -1) continue;

      if (!chk[nr][nc][broken][!tFlag] && Map[nr][nc] == 0) {
        chk[nr][nc][broken][!tFlag] = true;
        q.push({nr, nc, d + 1, broken, !tFlag});
      }
      if (!chk[nr][nc][broken + 1][!tFlag] && Map[nr][nc] == 1 && broken < K) {
        if (tFlag) {
          chk[nr][nc][broken + 1][!tFlag] = true;
          q.push({nr, nc, d + 1, broken + 1, !tFlag});
        } else if (!chk[nr][nc][broken][!tFlag]) {
          chk[r][c][broken][!tFlag] = true;
          q.push({r, c, d + 1, broken, !tFlag});
        }
      }
    }
  }
  if (ans != 1e9) cout << ans << '\n';
  else cout << -1 << '\n';
}