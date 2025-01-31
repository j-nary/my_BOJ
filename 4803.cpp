//BOJ_4803 트리 [골드 4]
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

int N, M;
vector<int> adj[502];
bool chk[502];

bool bfs(int root) {
  queue<int> q;
  q.push(root);

  int edgeCnt = 0, vertexCnt = 0;
  while(!q.empty()) {
    int cur = q.front(); q.pop();
    chk[cur] = true;
    vertexCnt++;

    for (int ch: adj[cur]) {  
      if (!chk[ch]) q.push(ch);
      edgeCnt++;
    }
  }

  if (edgeCnt / 2 == vertexCnt - 1) return true;
  return false;
}
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  for (int c = 1; ; c++) {
    cin >> N >> M;
    if (!N && !M) break;
    
    memset(chk, false, sizeof(chk));
    for (int i = 0; i <= N; i++) adj[i].clear();

    for (int i = 0; i < M; i++) {
      int u, v; cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) if (!chk[i]) ans += bfs(i);

    cout << "Case " << c << ": ";
    if (ans == 1) cout << "There is one tree.\n";
    else if (ans) cout << "A forest of " << ans << " trees.\n";
    else cout << "No trees.\n";
  }
}