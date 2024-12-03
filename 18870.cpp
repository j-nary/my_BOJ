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
  for (int i = 0; i < N; i++) {
    int idx = i;
    while(idx > 0 && v[idx] == v[idx - 1]) idx--;

    ans[v[i].second] = idx;
  }

  for (auto a: ans) cout << a << ' ';
  cout << '\n';
}