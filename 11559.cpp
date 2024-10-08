//BOJ_11559 Puyo Puyo [골드 4]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

char Puyo[15][10];
bool chk[15][10], pangFlag;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void sortPuyo() {
  for (int c = 1; c <= 6; c++) {
    for (int r = 12; r > 0; r--) {
      int nr = r, nc = c;
      while (Puyo[nr][nc] == '.' && nr > 0) nr--;
      if (r == 0) break;
      swap(Puyo[nr][nc], Puyo[r][c]);  
    }
  }
}

void bfs(int curr, int curc) {
  queue<pair<int, int>> q;
  vector<pair<int, int>> pangElem;

  q.push({curr, curc}), pangElem.push_back({curr, curc});
  chk[curr][curc] = true;
  char stnd = Puyo[curr][curc];

  while (!q.empty()) {
    int r = q.front().first, c = q.front().second; q.pop();

    for (int i = 0; i < 4; i++) {
      int nr = r + dir[i][0], nc = c + dir[i][1];
      if (chk[nr][nc] || !Puyo[nr][nc] || Puyo[nr][nc] != stnd) continue;
      chk[nr][nc] = true;
      q.push({nr, nc}), pangElem.push_back({nr, nc});
    }
  }
  if (pangElem.size() >= 4) {
    pangFlag = true;
    for (auto elem: pangElem) Puyo[elem.first][elem.second] = '.';
    sortPuyo();
  }
}

void pang() {
  memset(chk, 0, sizeof(chk)), pangFlag = false;

  for (int i = 1; i <= 12; i++)
    for (int j = 1; j <= 6; j++)
      if (Puyo[i][j] != '.' && !chk[i][j]) bfs(i, j);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  for (int i = 1; i <= 12; i++)
    for (int j = 1; j <= 6; j++) cin >> Puyo[i][j];

  int ans = 0;
  while(1) {
    pang(); 
    if (pangFlag) ans++; else break;
  }
  cout << ans << '\n';
}