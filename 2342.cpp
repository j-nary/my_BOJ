//BOJ_2342 Dance Dance Revolution [골드 3]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<int> order;
int dp[100005][5][5];   // 단계, 왼발, 오른발일 때의 비용
int weight[5][5] = {{1, 2, 2, 2, 2},
                    {0, 1, 3, 4, 3},
                    {0, 3, 1, 3, 4},
                    {0, 4, 3, 1, 3},
                    {0, 3, 4, 3, 1}};

int dfs(int step, int left, int right) {
  if (step == order.size()) return 0;
  if (left && right && left == right) return 1e9;

  if (dp[step][left][right]) return dp[step][left][right];

  int nxt = order[step + 1];
  return dp[step][left][right] = min(dfs(step + 1, nxt, right) + weight[left][nxt],
                                    dfs(step + 1, left, nxt) + weight[right][nxt]);
}
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int ip;
  order.push_back(-1);
  while(1) {
    cin >> ip;
    if (!ip) break;
    order.push_back(ip);
  }

  cout << dfs(0, 0, 0) << '\n';
}