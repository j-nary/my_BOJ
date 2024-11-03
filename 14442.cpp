//BOJ_14442 벽 부수고 이동하기 2 [골드 3]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

int N, M, K;
int Map[1003][1003];
bool chk[1003][1003][10];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
struct node {
  int r, c, d, b;
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
  q.push({1, 1, 1, 0});
  while (!q.empty()) {
    auto [r, c, d, b] = q.front();
    q.pop();

    if (r == N && c == M) {
      cout << d << '\n';
      return 0;
    }

    for (int i = 0; i < 4; i++) {
      int nr = r + dir[i][0];
      int nc = c + dir[i][1];

      if (Map[nr][nc] == -1) continue;

      if (!chk[nr][nc][b + 1] && Map[nr][nc] == 1 && b < K) {
        chk[nr][nc][b + 1] = true;
        q.push({nr, nc, d + 1, b + 1});
      }
      if (!chk[nr][nc][b] && Map[nr][nc] == 0) {
        chk[nr][nc][b] = true;
        q.push({nr, nc, d + 1, b});
      }
    }
  }

  cout << -1 << '\n';
}