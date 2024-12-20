//BOJ_1916 최소비용 구하기 [골드 5]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

const int INF = 1e9;
struct node {
  int target, weight;
  bool operator<(const node &a) const {
    return a.weight < weight; // 가중치 더 큰 노드가 먼저 오도록
  }
};

vector<node> adj[20004];
vector<int> dist(20004, INF);
bool chk[20004];

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int V, E;
  cin >> V >> E;

  for (int i = 0; i < E; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
  }

  int startV, endV; cin >> startV >> endV;

  dist[startV] = 0;
  priority_queue<node> pq;
  pq.push({startV, 0});

  while(!pq.empty()) {
    node cur = pq.top();
    pq.pop();
    
    if (cur.target == endV) {
      cout << dist[cur.target] << '\n';
      return 0;
    }

    if (chk[cur.target]) continue;
    chk[cur.target] = true;

    for (auto &nxt: adj[cur.target]) {
      if (chk[nxt.target]) continue;

      int path = cur.weight + nxt.weight;
      if (dist[nxt.target] > path) {
        dist[nxt.target] = path;
        // 갱신됐을 경우 삽입
        pq.push({nxt.target, path});
      }
    }
  }

}