//BOJ_1949 우수 마을 [골드 2]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int N;
vector<int> cnt;
vector<int> adj[10004];
bool chk[10004];

int dp[10004][2];
// 일반 마을은 자식 마을이 우수하거나 자식 마을이 일반 마을
// dp[cur][0] += max(dp[nxt][0], dp[nxt][1])
// 현재 마을이 우수 마을이면, 자식은 반드시 일반 마을
// dp[cur][1] += dp[cur][0]

void dfs(int cur) {
  if (chk[cur]) return;
  chk[cur] = true;
  
  dp[cur][0] = 0;
  dp[cur][1] = cnt[cur];

  for (auto nxt: adj[cur]) {
    if (chk[nxt]) continue;

    dfs(nxt);
    
    dp[cur][0] += max(dp[nxt][0], dp[nxt][1]);
    dp[cur][1] += dp[nxt][0];
  }
}
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  cin >> N;
  cnt.resize(N + 1);
  for (int i = 1; i <= N; i++) cin >> cnt[i];
  for (int i = 0; i < N - 1; i++) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs(1);
  cout << max(dp[1][0], dp[1][1]) << '\n';
}