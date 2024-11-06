//BOJ_21608 상어 초등학교 [골드 5]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int fav[402][4];
vector<int> order;
pair<int, int> loc[402];
int cnt[21][21];
int chk[21][21];

struct node {
  int r, c, w;
};

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N; cin >> N;
  for (int i = 1; i <= N * N; i++) loc[i] = {-1, -1};
  for (int i = 0; i < N * N; i++) {
    int ip; cin >> ip;
    order.push_back(ip);
    for (int j = 0; j < 4; j++) cin >> fav[ip][j];
  }

  for (auto cur: order) {
    int maxCnt = 0;
    memset(cnt, 0, sizeof(cnt));
    for (auto adj: fav[cur]) {
      if (loc[adj].first == -1) continue;
      for (int i = 0; i < 4; i++) {
        int nr = loc[adj].first + dir[i][0];
        int nc = loc[adj].second + dir[i][1];
        if (chk[nr][nc] || nr < 1 || nc < 1 || nr > N || nc > N) continue;
        maxCnt = max(maxCnt, ++cnt[nr][nc]);
      }
    }
    pair<int, int> ans;
    int ansCnt = -1;
    for (int r = 1; r <= N; r++) {
      for (int c = 1; c <= N; c++) {
        if (cnt[r][c] != maxCnt) continue;
        int curCnt = 0;
        for (int k = 0; k < 4; k++) {
          int nr = r + dir[k][0];
          int nc = c + dir[k][1];
          if (nr < 1 || nc < 1 || nr > N || nc > N) continue;
          if (!chk[nr][nc]) curCnt++;
        }
        if (ansCnt < curCnt) {
          ans = {r, c};
          ansCnt = curCnt;
        }
      }
    }
    loc[cur] = ans;
    chk[ans.first][ans.second] = cur;
  }

  int manjok = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      int idx = chk[i][j];
      int curCnt = 0;
      for (int k = 0; k < 4; k++) {
        int nr = i + dir[k][0];
        int nc = j + dir[k][1];

        if (nr < 1 || nc < 1 || nr > N || nc > N) continue;

        for (auto adj: fav[idx]) {
          if (chk[nr][nc] == adj) curCnt++;
        }
      }
      manjok += (curCnt == 0 ? 0 : pow(10, curCnt - 1));
    }
  }
  cout << manjok << '\n';
}
