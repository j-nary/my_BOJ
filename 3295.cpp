//BOJ_3295 단방향 링크 네트워크 [플래티넘 2]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int N, M;
int A[1003], B[2003];
vector<int> adj[1003];
bool chk[1003];

bool dfs(int a) {
  chk[a] = true;
  for (int b: adj[a]) {
    if (B[b] == -1 || !chk[B[b]] && dfs(B[b])) {
      A[a] = b;
      B[b] = a;
      return true;
    }
  }
  return false;
}

void test_case() {
  memset(A, -1, sizeof(A));
  memset(B, -1, sizeof(B));

  cin >> N >> M;
  for (int i = 0; i < N; i++) adj[i].clear();

  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v + N);
  }

  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (A[i] != -1) continue;
    memset(chk, false, sizeof(chk));
    ans += dfs(i);
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int tc; cin >> tc;
  for (int t = 1; t <= tc; t++) {
    test_case();
  }
}

// 4  3

// 3 - 2
// 1 - 0
// 2 - 3

// 0 - 1
// 1 - 2
// 2 - 3
// 3   1
// 3 - 4
// 4 - 5