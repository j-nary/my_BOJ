//BOJ_11438 LCA 2 [플래티넘 5]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAX = 100005;
const int MAX_D = 18;

int parent[MAX][MAX_D];
int depth[MAX];
vector<int> adj[MAX];

void makeTreeByDFS(int cur) {
  for (int nxt: adj[cur]) {
    if (depth[nxt] != -1) continue;
    parent[nxt][0] = cur;
    depth[nxt] = depth[cur] + 1;
    makeTreeByDFS(nxt);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  
  memset(parent, -1, sizeof(parent));
  memset(depth, -1, sizeof(depth));

  int N; cin >> N;
  for (int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v;
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  depth[0] = 0;
  makeTreeByDFS(0);

  for (int j = 1; j < MAX_D; j++)
    for (int i = 1; i < N; i++)
      if (parent[i][j - 1] != -1) parent[i][j] = parent[parent[i][j - 1]][j - 1];

  int M; cin >> M;
  while (M--) {
    int u, v; cin >> u >> v;
    u--; v--;

    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];

    for (int j = 0; j < MAX_D; j++) {
      if (diff & (1 << j)) u = parent[u][j];
    }

    if (u != v) {
      for (int j = MAX_D - 1; j >= 0; j--) {
        if (parent[u][j] != -1 && parent[u][j] != parent[v][j]) {
          u = parent[u][j];
          v = parent[v][j];
        }
      }
      u = parent[u][0];
    }
    cout << u + 1 << '\n';
  }
}