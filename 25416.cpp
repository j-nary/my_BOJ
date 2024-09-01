//BOJ_25416 빠른 숫자 탐색 [실버 2]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

int Graph[10][10];
bool chk[10][10];

struct node {
  int r, c, d;
};

queue<node> q;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  memset(Graph, -1, sizeof(Graph));

  for (int i = 1; i <= 5; i++) {
    for (int j = 1; j <= 5; j++) {
      cin >> Graph[i][j];
    }
  }

  int curR, curC;
  cin >> curR >> curC;

  q.push({curR + 1, curC + 1, 0});
  chk[curR][curC] = true;

  while(!q.empty()) {
    auto [r, c, d] = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nr = r + dir[i][0];
      int nc = c + dir[i][1];

      if (Graph[nr][nc] == 1) {
        cout << d + 1 << '\n';
        return 0;
      } else if (Graph[nr][nc] == 0 && !chk[nr][nc]) {
        chk[nr][nc] = true;
        q.push({nr, nc, d + 1});
      }
    }
  }

  cout << -1 << '\n';

}