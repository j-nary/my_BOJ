#include <bits/stdc++.h>
#include <iostream>
#include <queue>
using namespace std;

bool visited[5][5];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int bfs(int r, int c, vector<vector<int>> board, int st)
{
  // q만 pair로 변경해봐 cnt 담을 필요 없어 q에
  queue<pair<int, int>> q;
  q.push({r, c});
  visited[r][c] = 1;
  int mx = 0;
  while (!q.empty())
  {
    int cr = q.front().first;
    int cc = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int nr = cr + dx[i];
      int nc = cc + dy[i];

      if (nr < 0 || nr >= 4 || nc < 0 || nc >= 4)
        continue;
      if (visited[nr][nc] || board[nr][nc] != st)
        continue;

      visited[nr][nc] = true;
      q.push({nr, nc});
      mx++;
    }
  }
  return mx;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int ans = 0;
  vector<vector<int>> board = {
      {3, 2, 3, 2},
      {2, 1, 1, 2},
      {1, 1, 2, 1},
      {4, 1, 1, 1}};

  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      if (!visited[i][j])
        ans = max(ans, bfs(i, j, board, board[i][j]));
    }
  }

  if (ans == 0)
    cout << -1 << '\n';
  else
    cout << ans << '\n';
}

// 3번 코드 좀 찍어갈게 뭐 바꿔야할지만 알려주게

// 아래 solution 함수도 보여줘

이 표를 우선 만들어야돼
    근데 이거 시간 좀 오래 걸릴 것 같아
        내가 이거 붙잡아볼게...