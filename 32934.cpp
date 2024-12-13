//BOJ_32934 풍성한 트리 [골드 4]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int N;
vector<int> adj[200005];
int depth[200005];

void makeTreeByDFS(int cur) {
  int degCnt = 0;
  for (int nxt: adj[cur]) {
    if (depth[nxt] != -1) continue;
    degCnt++;
    depth[nxt] = depth[cur] + 1;
    makeTreeByDFS(nxt);
  }
}

bool isPromising(int root) {
  memset(depth, -1, sizeof(depth));
  depth[root] = 0;
  makeTreeByDFS(root);

  int dist = -1;
  for (int i = 1; i <= N; i++) {
    if (adj[i].size() == 1) {
      if (dist < 0) dist = depth[i];
      else if (dist != depth[i]) return false;
    }
  }

  return true;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  cin >> N;

  for (int i = 0; i < N - 1; i++) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<int> root;
  for (int i = 1; i <= N; i++) {
    if (adj[i].size() != 3 && adj[i].size() != 1) {
      cout << -1 << '\n';
      return 0;
    }
  }

  for (int i = 1; i <= N; i++) {
    if (adj[i].size() == 3) root.push_back(i);
  }

  vector<int> ans;
  for (int r: root) {
    if (isPromising(r)) ans.push_back(r);
  }

  if (ans.empty()) {
    cout << -1 << '\n';
    return 0;
  }
  
  cout << ans.size() << '\n';
  for (auto r: ans) cout << r << '\n';
}