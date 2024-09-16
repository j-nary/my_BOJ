//BOJ_2589 보물섬 [골드 5]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

char Map[51][51];
bool chk[51][51];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
struct node {
  int r, c, d;
};

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int L, W;
  cin >> L >> W;

  queue<pair<int, int>> startPoint;
  for(int i = 1; i <= L; i++) {
    for (int j = 1; j <= W; j++) {
      cin >> Map[i][j];
      if (Map[i][j] == 'L') startPoint.push({i, j});
    }
  }

  int ans = 0;
  while (!startPoint.empty()) {
    auto [sr, sc] = startPoint.front();
    startPoint.pop();

    memset(chk, false, sizeof(chk));
    chk[sr][sc] = true;

    queue<node> q;
    q.push({sr, sc, 0});

    while(!q.empty()) {
      auto [r, c, d] = q.front();
      q.pop();

      ans = max(ans, d);

      for (int i = 0; i < 4; i++) {
        int nr = r + dir[i][0];
        int nc = c + dir[i][1];

        if (Map[nr][nc] == 'L' && !chk[nr][nc]) {
          chk[nr][nc] = true;
          q.push({nr, nc , d + 1});
        }
      }
    }
  }

  cout << ans << '\n';
}