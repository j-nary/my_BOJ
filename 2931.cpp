//BOJ_2931 가스관 [골드 2]
#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <queue>

using namespace std;

struct node { int r, c;};

int R, C;
char Block[30][30];
bool chk[30][30];
node Mockba, Zagreb;
map<char, vector<int>> pipe;   // 북동남서
char dirPipe[4][4] = {
    {'|', '+', '1', '4'},
    {'-', '+', '3', '4'},
    {'|', '+', '2', '3'},
    {'-', '+', '1', '2'}
};
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void init() {
  cin >> R >> C;
  for (int i = 1; i <= R; i++) {
    for (int j = 1; j <= C; j++) {
      cin >> Block[i][j];
      if (Block[i][j] == 'M') Mockba = {i, j};
      else if (Block[i][j] == 'Z') Zagreb = {i, j};
    }
  }

  pipe['|'] = {0, 2};
  pipe['-'] = {1, 3};
  pipe['+'] = {0, 1, 2, 3};
  pipe['1'] = {1, 2};
  pipe['2'] = {0, 1};
  pipe['3'] = {0, 3};
  pipe['4'] = {2, 3};
}

void findNeed(node spot) {
  vector<int> needs;
  vector<int> tmp;
  for (int i = 0; i < 4; i++) {
    int nr = spot.r + dir[i][0];
    int nc = spot.c + dir[i][1];
    char nBlock = Block[nr][nc];
    if (nBlock && nBlock != '.') {
      if (nBlock == 'M' || nBlock == 'Z') tmp.push_back(i);
      else if (find(pipe[nBlock].begin(), pipe[nBlock].end(), (i + 2) % 4) != pipe[nBlock].end()) {
        needs.push_back(i);
      }
    }
  }

  for (auto iter : pipe) {
    if (iter.second == needs) {
      cout << iter.first << '\n';
      return;
    }
  }

  for (int i = 0; i < tmp.size(); i++) needs.push_back(tmp[i]);
  sort(needs.begin(), needs.end());
  for (auto iter : pipe) {
    if (iter.second == needs) {
      cout << iter.first << '\n';
      return;
    }
  }
}
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  init();

  node spot = {-1, -1};
  queue<node> q;

  // M으로 이어진 길부터 시작
  for (int i = 0; i < 4; i++) {
    int ncr = Mockba.r + dir[i][0];
    int ncc = Mockba.c + dir[i][1];
    char nBlock = Block[ncr][ncc];
    if (Block[ncr][ncc] && Block[ncr][ncc] != '.') {
      if (find(pipe[nBlock].begin(), pipe[nBlock].end(), (i + 2) % 4) != pipe[nBlock].end()) {
        chk[ncr][ncc] = true;
        chk[Mockba.r][Mockba.c] = true;
        q.push({ncr, ncc});
        break;
      }
    }
  }

  // M으로 이어진 길이 없는 경우 Z부터 시작
  if (q.empty()) {
    for (int i = 0; i < 4; i++) {
      int ncr = Zagreb.r + dir[i][0];
      int ncc = Zagreb.c + dir[i][1];
      char nBlock = Block[ncr][ncc];
      if (Block[ncr][ncc] && Block[ncr][ncc] != '.') {
        if (find(pipe[nBlock].begin(), pipe[nBlock].end(), (i + 2) % 4) != pipe[nBlock].end()) {
          chk[ncr][ncc] = true;
          chk[Zagreb.r][Zagreb.c] = true;
          q.push({ncr, ncc});
          break;
        }
      }
    }
  }

  // M부터 Z를 연결하는 가스관이 한개인 경우
  // 하나의 블록과 인접해있는 입력만 주어진다고 했으니 이 경우는 없을지도?
  if (q.empty()) {
    q.push({Mockba.r, Mockba.c});
    chk[Mockba.r][Mockba.c] = true;

    while(!q.empty()) {
      node cur = q.front();
      q.pop();

      for (int i = 0; i < 4; i++) {
        int nr = cur.r + dir[i][0];
        int nc = cur.c + dir[i][1];

        if (!Block[nr][nc] || chk[nr][nc]) continue;
        if (Block[nr][nc] == 'Z') {
          spot = cur;
          break;
        }
        chk[nr][nc] = true;
        q.push({nr, nc});
      }

      if (spot.r != -1) break;
    }

    cout << spot.r << ' ' << spot.c << ' ';
    findNeed(spot);

    return 0;
  }

  while(!q.empty()) {
    node cur = q.front();
    q.pop();

    char p = Block[cur.r][cur.c];

    for (int i = 0; i < pipe[p].size(); i++) {
      int nr = cur.r + dir[pipe[p][i]][0];
      int nc = cur.c + dir[pipe[p][i]][1];

      if (!Block[nr][nc] || chk[nr][nc]) continue;
      if (Block[nr][nc] == '.') {
        spot = {nr, nc};
        break;
      }

      chk[nr][nc] = true;
      q.push({nr, nc});
    }

    if (spot.r != -1) break;
  }

  cout << spot.r << ' ' << spot.c << ' ';
  findNeed(spot);
}