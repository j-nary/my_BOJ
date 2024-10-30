//BOJ_5972 택배 배송 [골드 5]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;
const int INF = 1e9;

struct node {
  int target, weight;
  bool operator<(const node &a) const {
    return a.weight < weight;
  }
};

vector<node> adj[500005];
vector<int> dist(500005, INF);
bool chk[500005];
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int V, E;
  cin >> V >> E;

  for (int i = 0; i < E; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  dist[1] = 0;
  priority_queue<node> pq;
  pq.push({1, 0});
  while(!pq.empty()) {
    auto [target, weight] = pq.top(); pq.pop();

    if (chk[target]) continue;
    chk[target] = true;

    for (auto &nxt: adj[target]) {
      if (chk[nxt.target]) continue;

      int path = weight + nxt.weight;
      if (dist[nxt.target] > path) {
        dist[nxt.target] = path;
        pq.push({nxt.target, path});
      }
    }
  }

  cout << dist[V] << '\n';
}