#include <bits/stdc++.h>
#include <iostream>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  ll N; cin >> N;
  ll sum = 0;
  vector<ll> sz(6);
  for (int i = 0; i < 6; i++) cin >> sz[i];

  ll T, P; cin >> T >> P;
  int tCnt = 0;
  for (int i = 0; i < sz.size(); i++) tCnt += ceil(sz[i] / (double) T);

  cout << tCnt << '\n' <<  N / P << " " << N % P << '\n';
}