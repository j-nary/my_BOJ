#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N; cin >> N;
  vector<pair<int, int>> v(N);
  for (int i =0; i < N; i++) {
    int ip; cin >> ip;
    v[i] = {ip, i};
  }

  sort(v.begin(), v.end());

  vector<int> ans(N);
  ans[v[0].second] = 0;
  int tmp = 0;
  for (int i = 1; i < N; i++) {
    int res = 0;
    if (v[i].first == v[i - 1].first) res = tmp;
    else res = ++tmp;
    ans[v[i].second] = res;
  }

  for(auto a: ans) cout << a << ' ';
  cout << '\n';
}
