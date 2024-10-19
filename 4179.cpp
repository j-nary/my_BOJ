//BOJ_4179 불! [골드 3]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

char Miro[1003][1003];
bool chk[1003][1003];
int Fire[1003][1003];
struct node { int r, c, d; };
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int R, C;
  cin >> R >> C;

  queue<node> f, q;
  for (int i = 1; i <= R; i++)
    for (int j  = 1; j <= C; j++) {
      cin >> Miro[i][j];
      if (Miro[i][j] == 'J') q.push({i, j, 1});
      else if (Miro[i][j] == 'F') f.push({i, j, 0});
    }

  memset(Fire, -1, sizeof(Fire));
  while (!f.empty()) {
    auto [fr, fc, fd] = f.front();
    f.pop();

    if (fd == 0) Fire[fr][fc] = 0;

    for (int i = 0; i < 4; i++) {
      int nr = fr + dir[i][0];
      int nc = fc + dir[i][1];

      if ((Miro[nr][nc] == '.' || Miro[nr][nc] == 'J') && Fire[nr][nc] == -1) {
        Fire[nr][nc] = fd + 1;
        f.push({nr, nc, fd + 1});
      }
    }
  }
  
  while (!q.empty()) {
    auto [r, c, d] = q.front(); q.pop();
    if (r == 1 || r == R || c == 1 || c == C) {
      cout << d << '\n';
      return 0;
    }

    for (int i = 0; i < 4; i++) {
      int nr = r + dir[i][0];
      int nc = c + dir[i][1];

      if (Miro[nr][nc] != '.' || Miro[nr][nc] == 'F' || chk[nr][nc] || (Fire[nr][nc] != -1 && Fire[nr][nc] < d + 1)) continue;

      chk[nr][nc] = true;
      if (nr == 1 || nr == R || nc == 1 || nc == C) {
        cout << d + 1 << '\n';
        return 0;
      }
      else q.push({nr, nc, d + 1});
    }
  }

  cout << "IMPOSSIBLE\n";
}