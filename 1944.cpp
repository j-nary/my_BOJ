//BOJ_1944 복제 로봇 [골드 1]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

char G[52][52];
int KN[52][52];

struct tree {
  int s, e, w;
  bool operator<(const tree &t) const {
    return this->w < t.w;
  }
};
vector<tree> T;

struct node {
  int r, c, d;
};
bool chk[52][52];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int parent[300];
int find(int n) {
  if (parent[n] < 0) return n;
  return parent[n] = find(parent[n]);
}
void merge(int a, int b) {
  a = find(a);
  b = find(b);
  if (a != b) parent[b] = a;
}

int BFS(int sr, int sc, int er, int ec) {
  memset(chk, false, sizeof(chk));
  chk[sr][sc] = true;

  queue<node> q;
  q.push({sr, sc, 0});

  while (!q.empty()) {
    auto [r, c, d] = q.front(); q.pop();

    for (int i = 0; i < 4; i++) {
      int nr = r + dir[i][0];
      int nc = c + dir[i][1];

      if (nr == er && nc == ec) return d + 1;

      if (chk[nr][nc] || G[nr][nc] == '1') continue;
      chk[nr][nc] = true;
      q.push({nr, nc, d + 1});
    }
  }

  return -1;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N, M, KIdx = 1; cin >> N >> M;
  pair<int, int> S;
  vector<pair<int, int>> K;

  for (int i = 0; i <= N + 1; i++)
    for (int j = 0; j <= N + 1; j++) G[i][j] = '1';

  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++) {
      cin >> G[i][j];
      if (G[i][j] == 'S') S = {i, j};
      else if (G[i][j] == 'K') {
        K.push_back({i, j});
        KN[i][j] = KIdx++;
      }
    }
  
  for (int i = 0; i < M; i++) {
    int StoK = BFS(S.first, S.second, K[i].first, K[i].second);
    if (StoK < 0) { cout << -1 << '\n'; return 0; }
    T.push_back({ 0, KN[K[i].first][K[i].second], StoK });
  }

  for (int i = 0; i < M - 1; i++) {
    auto [r1, c1] = K[i];
    for (int j = i + 1; j < M; j++) {
      auto [r2, c2] = K[j];
      int KtoK = BFS(r1, c1, r2, c2);
      if (KtoK < 0) { cout << -1 << '\n'; return 0; }
      T.push_back({ KN[r1][c1], KN[r2][c2], KtoK });
    }
  }

  sort(T.begin(), T.end());
  memset(parent, -1, sizeof(parent));
  int ans = 0;
  for (auto [r, c, w]: T) {
    if (find(r) == find(c)) continue;
    merge(r, c);
    ans += w;
  }

  cout << ans << '\n';
}