#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N; cin >> N;
  vector<int> v(N);
  for (int i = 0; i < N; i++) cin >> v[i];

  sort(v.begin(), v.end());

  int cnt = 0;
  for (int i = 0; i < N - 1; i++) cnt += v[i];
  cout << cnt <<'\n';
}