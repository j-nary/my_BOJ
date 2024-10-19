//BOJ_11048 이동하기 [실버 2]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

int Miro[1003][1003];
int dp[1003][1003];
int dir[4][2] = {{1, 0}, {0, 1}, {1, 1}};

struct node {
  int r, c, cnt;
};

int dfs(int r, int c) {
  if (r == 1 && c == 1) return dp[r][c] = Miro[1][1];

  if (dp[r][c] != -1) return dp[r][c];

  int path = 0;
  if (r-1 > 0) path = dfs(r-1, c);
  if (c-1 > 0) path = max(path, dfs(r, c-1));
  // if (r-1 > 0 && c-1 > 0) path = max(path, dfs(r-1, c-1));

  return dp[r][c] = path + Miro[r][c];
}
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N, M;
  cin >> N >> M;
  
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++) cin >> Miro[i][j];
  
  memset(dp, -1, sizeof(dp));
  cout << dfs(N, M) << '\n';
}