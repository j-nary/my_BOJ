//BOJ_30024 옥수수밭 [골드 4]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

int N, M, K;
int Corn[1003][1003];
bool chk[1003][1003];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

struct node {
  int w, r, c;
  bool operator<(const node& other) const {
    return w < other.w;
  }
};
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  cin >> N >> M;

  priority_queue<node> pq;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++) {
      cin >> Corn[i][j];
      if (i == 1 || i == N || j == 1 || j == M) {
        chk[i][j] = true;
        pq.push({Corn[i][j], i, j});
      }
    }
  cin >> K;

  while (K--) {
    auto [w, r, c] = pq.top();
    pq.pop();
    cout << r << ' ' << c << '\n';

    for (int i = 0; i < 4; i++) {
      int nr = r + dir[i][0];
      int nc = c + dir[i][1];

      if (chk[nr][nc] || !Corn[nr][nc]) continue;
      chk[nr][nc] = true;
      pq.push({Corn[nr][nc], nr, nc});
    }

  }
}