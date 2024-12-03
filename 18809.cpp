//BOJ_18809 Gaaaaaaaaaarden [골드 1]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

int N, M, G, R, possibleSize, ans;
int MAP[52][52];  // 0 호수 1 배양액X 2 배양액
int tmp[52][52];
vector<pair<int, int>> possible;
bool chk[52][52];
bool tmpChk[52][52];
vector<int> Green, Red;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

struct node { int r, c, d; };

void simulate() {
  for (int i = 0; i < 52; i++)
    for (int j = 0; j < 52; j++) {
      tmp[i][j] = MAP[i][j];
    }
  memset(tmpChk, 0, sizeof(tmpChk));

  queue<node> gq;
  queue<node> rq;

  for (auto g: Green) {
    gq.push({possible[g].first, possible[g].second, 0});
    tmp[possible[g].first][possible[g].second] = 0;
    tmpChk[possible[g].first][possible[g].second] = true;
  }
  for (auto r: Red) {
    rq.push({possible[r].first, possible[r].second, 0});
    tmp[possible[r].first][possible[r].second] = 0;
    tmpChk[possible[r].first][possible[r].second] = true;
  }

  int flowerCnt = 0;

  while (!gq.empty() && !rq.empty()) {
    int r = 0, c = 0, d = 1e9;
    if (gq.size() > 0) { r = gq.front().r; c = gq.front().c; d = gq.front().d; }
    int rr = 0, rc = 0, rd = 1e9;
    if (rq.size() > 0) { rr = rq.front().r; rc = rq.front().c; rd = rq.front().d; }

    if (d == rd) { gq.pop(); rq.pop(); }
    else if (d < rd) { rd = -1; gq.pop(); }
    else if (d > rd) { d = -1; rq.pop(); }

    bool breakFlag = false;
    while (tmp[r][c] == -1) {
      if (gq.empty()) { breakFlag = true; break; }
      r = gq.front().r; c = gq.front().c; d = gq.front().d;
      if (rd != -1 && rd < d) { d = -1; break; }
      gq.pop();
    }

    while (tmp[rr][rc] == -1) {
      if (rq.empty()) { breakFlag = true; break; }
      rr = rq.front().r; rc = rq.front().c; rd = rq.front().d;
      if (d != -1 && rd > d) { rd = -1; break; }
      rq.pop();
    }

    if (breakFlag) break;

    for (int i = 0; i < 4; i++) {
      if (d != -1) {
        int nr = r + dir[i][0], nc = c + dir[i][1];
        if (!tmpChk[nr][nc] && tmp[nr][nc] > 0) {
          tmpChk[nr][nc] = true;
          tmp[nr][nc] = d + 1;
          gq.push({nr, nc, d + 1});
        } else if (tmpChk[nr][nc] && tmp[nr][nc] == d + 1) {
          flowerCnt++;
          tmp[nr][nc] = -1;
        }
      }

      if (rd != -1) {
        int nrr = rr + dir[i][0], nrc = rc + dir[i][1];
        if (!tmpChk[nrr][nrc] && tmp[nrr][nrc] > 0) {
          tmpChk[nrr][nrc] =  true;
          tmp[nrr][nrc] = rd + 1;
          rq.push({nrr, nrc, rd + 1});
        } else if (tmpChk[nrr][nrc] && tmp[nrr][nrc] == rd + 1) {
          flowerCnt++;
          tmp[nrr][nrc] = -1;
        }
      }
    }
  }
  
  ans = max(ans, flowerCnt);
}

void selectRed(int idx, int cnt) {
  if (cnt == R) { simulate(); return; }

  for (int i = idx; i < possibleSize; i++) {
    if (chk[possible[i].first][possible[i].second]) continue;
    chk[possible[i].first][possible[i].second] = true;
    Red.push_back(i);
    selectRed(i + 1, cnt + 1);
    chk[possible[i].first][possible[i].second] = false;
    Red.pop_back();
  }
}

void selectGreen(int idx, int cnt) {
  if (cnt == G) { selectRed(0, 0); return; }

  for (int i = idx; i < possibleSize; i++) {
    if (chk[possible[i].first][possible[i].second]) continue;
    chk[possible[i].first][possible[i].second] = true;
    Green.push_back(i);
    selectGreen(i + 1, cnt + 1);
    chk[possible[i].first][possible[i].second] = false;
    Green.pop_back();
  }
}


int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  cin >> N >> M >> G >> R;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++) {
      cin >> MAP[i][j];
      if (MAP[i][j] == 2) possible.push_back({i, j});
    }
  
  possibleSize = possible.size();
  selectGreen(0, 0);
  
  cout << ans << '\n';
}