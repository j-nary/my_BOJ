#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool rChk[10][10], bChk[10][10];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
pair<int, int> rDest, bDest;
int N, M, res = INT_MAX;
vector<vector<int>> G;
void backtracking(int rr, int rc, int br, int bc, int d) {
    if (rDest.first == rr && rDest.second == rc && bDest.first == br && bDest.second == bc) {
      res = min(res, d);
      return;
    }

    for (int i = 0; i < 4; i++) {
      int nrr = rr + dir[i][0], nrc = rc + dir[i][1];
      if (rDest.first == rr && rDest.second == rc) { nrr = rr; nrc = rc; }
      else {
        if (nrr < 0 || nrr >= N || nrc < 0 || nrc >= M) continue;
        if (rChk[nrr][nrc] || G[nrr][nrc] == 5) continue;
      }

      for (int j = 0; j < 4; j++) {
        int nbr = br + dir[j][0], nbc = bc + dir[j][1];
        if (bDest.first == br && bDest.second == bc) { nbr = br; nbc = bc; }
        else {
          if (nbr < 0 || nbr >= N || nbc < 0 || nbc >= M) continue;
          if (bChk[nbr][nbc] || G[nbr][nbc] == 5) continue;
        }

        // 동시에 같은 칸 X
        if (nrr == nbr && nrc == nbc) continue;
        // 자리 바꾸기 X
        if (nrr == br && nrc == bc && rr == nbr && rc == nbc) continue;


        rChk[nrr][nrc] = true;
        bChk[nbr][nbc] = true;
        backtracking(nrr, nrc, nbr, nbc, d + 1);
        rChk[nrr][nrc] = false;
        bChk[nbr][nbc] = false;
      }
    }
}
int solution(vector<vector<int>> maze) {
    G = maze;
    N = maze.size(); M = maze[0].size();

    pair<int, int> rStart, bStart;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (maze[i][j] == 1) rStart = {i, j};
        else if (maze[i][j] == 2) bStart = {i, j};
        else if (maze[i][j] == 3) rDest = {i, j};
        else if (maze[i][j] == 4) bDest = {i, j};
      }
    }

    rChk[rStart.first][rStart.second] = true;
    bChk[bStart.first][bStart.second] = true;
    backtracking(rStart.first, rStart.second, bStart.first, bStart.second, 0);
    
    if (res == INT_MAX) return 0;
    return res;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  // vector<vector<int>> maze = {{1, 4}, {0, 0}, {2, 3}};
  vector<vector<int>> maze = {{1, 0, 2}, {0, 0, 0}, {5, 0, 5}, {4, 0, 3}};
  cout << solution(maze) << '\n';
}