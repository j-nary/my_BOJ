//BOJ_1261 알고스팟 [골드 4]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>
using namespace std;

char Miro[102][102];
bool chk[102][102][10004];
struct node {
  int r, c, broken;
};
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N, M;
  cin >> N >> M;
  for (int i = 1; i <= M; i++)
    for (int j = 1; j <= N; j++) cin >> Miro[i][j];

  queue<node> q;
  q.push({1, 1, 0});
  chk[1][1][0] = true;
  int ans = 1e9;
  while (!q.empty()) {
    auto [r, c, broken] = q.front(); q.pop();

    if (r == M && c == N) {
      ans = min(ans, broken);
      continue;
    }
    for (int i = 0; i < 4; i++) {
      int nr = r + dir[i][0];
      int nc = c + dir[i][1];
      int cur = Miro[nr][nc];

      if (!cur) continue;
      if (cur == '1') {
        if (chk[nr][nc][broken + 1]) continue;
        chk[nr][nc][broken + 1] = true;
        q.push({nr, nc, broken + 1});
      } else {
        if (chk[nr][nc][broken]) continue;
        chk[nr][nc][broken] = true;
        q.push({nr, nc, broken});
      }
    }
  }
  cout << ans << '\n';
}