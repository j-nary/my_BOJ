//BOJ_2961 도영이가 만든 맛있는 음식 [실버 2]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<int> sour;
vector<int> salt;
int ans = 1e9;
int N;

void dfs(int idx, int sourMul, int saltySum) {
  if (idx == N) {
    ans = min(ans, abs(sourMul-saltySum));
    return;
  }
  dfs(idx + 1, sourMul, saltySum);
  dfs(idx + 1, sourMul * sour[idx], saltySum * salt[idx]);
}
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  cin >> N;
  for (int i = 0; i < N; i++){
    int a, b;
    cin >> a >> b;
    sour.push_back(a);
    salt.push_back(b);
  }

  dfs(0, 1, 0);
  cout << ans << '\n';
}