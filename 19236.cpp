//BOJ_19236 청소년 상어 [골드 2]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

int dir[9][2] = {{0, 0}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};
// ↑, ↖, ←, ↙, ↓, ↘, →, ↗ 
int res = 0;

struct node {
  int n, r, c;  // 물고기 번호, x, y
};

bool outOfBound(int r, int c) {
  return (r == 0 || r == 5 || c == 0 || c == 5);
}
void fishSimulate(pair<int, int> cur[5][5]) {
  for (int i = 1; i <= 16; i++) {
    int r = 0, c = 0;
    for (int p = 1; p <= 4; p++) {
      for (int q = 1; q <= 4; q++) {
        if (cur[p][q].first == i) {
          r = p;
          c = q;
          break;
        }
      }
      if (r) break;
    }

    if (!r) continue;

    int nr = 0, nc = 0;
    int originR = r, originC = c;

    while(1) {
      nr = r + dir[cur[r][c].second][0];
      nc = c + dir[cur[r][c].second][1];
      if (originR == nr && originC == nc) break;

      // 상어가 있거나 경계를 벗어난 경우
      if (cur[nr][nc].first == 0 || outOfBound(nr, nc)) {
        // 45도 회전
        cur[r][c].second = ((cur[r][c].second + 1) % 9) + 1;
      } else {
        swap(cur[r][c], cur[nr][nc]);
        break;
      }
    }
  }
}

void dfs(const pair<int, int> M[5][5], int weight, pair<int, int> shark) {
  pair<int, int> cur[5][5];
  copy(&M[0][0], &M[0][0] + 25, &cur[0][0]);

  fishSimulate(cur);
  int d = cur[shark.first][shark.second].second;

  bool flag = true;
  int nr, nc;
  while(1) {
    if (d > 8) break;
    nr = shark.first + dir[d][0];
    nc = shark.second + dir[d++][1];
    if (cur[nr][nc].first == 0) continue;
    if (!outOfBound(nr, nc)) {
      flag = false;
      pair<int, int> tmp = M[nr][nc];
      cur[nr][nc].first = 0;
      // dfs(cur, weight + tmp.first, shark);
      cur[nr][nc] = tmp;
    } else {
      break;
    }
  }

  if (flag) res = max(res, weight);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  pair<int, int> MAP[5][5];
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= 4; j++) {
      cin >> MAP[i][j].first >> MAP[i][j].second;
    }
  }

  // 상어 (1, 1)로 이동
  MAP[1][1].first = 0;
  dfs(MAP, MAP[1][1].first, {1, 1});

  cout << res << '\n';
}