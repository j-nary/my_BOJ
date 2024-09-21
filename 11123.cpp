//BOJ_11123 양 한마리... 양 두마리... [실버 2]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

char Grid[102][102];
bool chk[102][102];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void BFS(int cr, int cc) {
  queue<pair<int, int>> q;
  q.push({cr, cc});

  while (!q.empty()) {
    auto [r, c] = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nr = r + dir[i][0];
      int nc = c + dir[i][1];

      if (!chk[nr][nc] && Grid[nr][nc] == '#') {
        chk[nr][nc] = true;
        q.push({nr, nc});
      }
    }
  }
}
void test_case() {
  int H, W; cin >> H >> W;

  memset(Grid, -1, sizeof(Grid));
  memset(chk, 0 , sizeof(chk));

  for (int i = 1; i <= H; ++i) {
    for (int j = 1; j <= W; ++j) {
      cin >> Grid[i][j];
    }
  }

  int cnt = 0;
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      if (Grid[i][j] == '#' && !chk[i][j]) {
        cnt++;
        chk[i][j] = true;
        BFS(i, j);
      }
    }
  }

  cout << cnt << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int tc; cin >> tc;
  for (int t = 1; t <= tc; t++) {
    test_case();
  }
}