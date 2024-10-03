//BOJ_15422 Bumped! [골드 1]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;
using ll = long long;
const ll INF = 1e18;
int N, M, F, S, T;
// 도시, 도로, 비행편, 시작도시, 목표도시
struct node {
  ll W, V;
  bool operator<(const node &a) const {
    return a.W < W; // 가중치 더 큰 노드가 먼저 오도록
  }
};
vector<node> adj[50004];
ll dist[50004];
bool chk[50004];
ll ans = INF;

void dijkstra() {
  int FS = -1, FT = -1;
  if (F) cin >> FS >> FT;

  priority_queue<node> pq;
  pq.push({0, S});
  while(!pq.empty()) {
    node cur = pq.top();
    pq.pop();

    if (cur.V == T) {
      ans = min(ans, dist[cur.V]);
      return;
    }

    if (cur.V == FS && dist[FT] > cur.W) {
      dist[FT] = cur.W;
      pq.push({cur.W, FT});
    }

    if (chk[cur.V]) continue;
    chk[cur.V] = true;

    for (auto &nxt: adj[cur.V]) {
      if (chk[nxt.V]) continue;

      ll path = cur.W + nxt.W;
      if (path < dist[nxt.V]) {
        dist[nxt.V] = path;
        pq.push({path, nxt.V});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  cin >> N >> M >> F >> S >> T;

  for (int i = 0; i < M; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({w, v});
    adj[v].push_back({w, u});
  }

  if (S == T) {
    cout << 0 << '\n';
    return 0;
  }
  do {
    fill(dist, dist + 50004, INF);
    memset(chk, 0, sizeof(chk));
    dijkstra();
  } while (F--);

  cout << ans << '\n';
}