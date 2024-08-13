// BOJ_1011 Fly me to the Alpha Centauri
// 그래프로는 죽어도 안 됨 -> 수학 악깡버
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;
using ll = long long;
struct node
{
  ll cur, k, depth;
};

// 메모리 초과
// void dfs(int cur, int k, int depth) {
//   if (cur == 0 && k == 1) {
//     ans = depth;
//     return;
//   } else if (cur <= 0) return;

//   if (k - 1 > 0 && cur - (k - 1) >= 0) dfs(cur - (k - 1), k - 1, depth + 1);
//   if (cur - k >= 0) dfs(cur - k, k, depth + 1);
//   if (cur - (k + 1) >= 0) dfs(cur - (k + 1), k + 1, depth + 1);
// }

void test_case()
{
  ll x, y;
  cin >> x >> y;
  ll dist = y - x;

  // dfs(dist - 1, 1, 1);

  queue<node> q;
  q.push({dist - 1, 1, 1});
  while (!q.empty())
  {
    auto [cur, k, depth] = q.front();
    q.pop();

    if (cur == 0 && k == 1)
    {
      cout << depth << '\n';
      break;
    }
    else if (cur <= 0)
      continue;

    if (k - 1 > 0 && cur - (k - 1) >= 0)
      q.push({cur - (k - 1), k - 1, depth + 1});
    if (cur - k >= 0)
      q.push({cur - k, k, depth + 1});
    if (cur - (k + 1) >= 0)
      q.push({cur - (k + 1), k + 1, depth + 1});
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tc;
  cin >> tc;
  for (int t = 1; t <= tc; t++)
  {
    test_case();
  }
}