//BOJ_16401 과자 나눠주기 [실버 2]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int M, N;
  cin >> M >> N;

  vector<ll> snack(N);
  ll left = 1, right = 0;
  for (int i = 0; i < N; i++) {
    cin >> snack[i];
    right += snack[i];
  }

  sort(snack.begin(), snack.end());

  ll ans = 0;
  while (left <= right) {
    ll mid = (left + right) / 2;

    int cnt = 0;
    for (int i = 0; i < N; i++) cnt += (snack[i] / mid);

    if (cnt >= M) { ans = max(ans, mid); left = mid + 1; }
    else right = mid - 1;
  }
  cout << ans << '\n';
}