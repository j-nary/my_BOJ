//BOJ_14400 편의점 2 [실버 2]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N; cin >> N;
  vector<pair<int, int>> v;
  for (int i = 0; i < N; i++) {
    int a, b; cin >> a >> b;
    v.push_back({a, b});
  }
  sort(v.begin(), v.end());
  int x = v[N / 2].first;

  sort(v.begin(), v.end(), [](const pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
  });
  int y = v[N / 2].second;

  long long ans = 0;
  for (int i = 0; i < N; i++) {
    ans += abs(x - v[i].first) + abs(y - v[i].second);
  }
  cout << ans << '\n';
}