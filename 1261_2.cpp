//BOJ_1261 알고스팟 [골드 4]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

const int INF = 1e9;
char Miro[102][102];
int N, M;
struct node {
  int tr, tc, weight;
  bool operator<(const node &a) const {
    return a.weight < weight;
  }
};
vector<node> adj[102][102];
int dist[102][102];
bool chk[102][102];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  fill(&dist[0][0], &dist[0][0] + 102*102, INF);
  cin >> M >> N;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++) cin >> Miro[i][j];

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      for (int k = 0; k < 4; k++) {
        int nr = i + dir[k][0];
        int nc = j + dir[k][1];
        if (Miro[nr][nc] == '0') adj[i][j].push_back({nr, nc, 0});
        else if (Miro[nr][nc] == '1') adj[i][j].push_back({nr, nc, 1});
      }
    }
  }

  dist[1][1] = 0;
  priority_queue<node> pq;
  pq.push({1, 1, 0});

  while (!pq.empty()) {
    auto [tr, tc, weight] = pq.top(); pq.pop();

    if (chk[tr][tc]) continue;
    chk[tr][tc] = true;

    for (auto &nxt: adj[tr][tc]) {
      if (chk[nxt.tr][nxt.tc]) continue;

      int path = weight + nxt.weight;
      if (dist[nxt.tr][nxt.tc] > path) {
        dist[nxt.tr][nxt.tc] = path;
        pq.push({nxt.tr, nxt.tc, path});
      }
    }
  }

  cout << dist[N][M] << '\n';
}