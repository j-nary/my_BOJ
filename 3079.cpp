//BOJ_3079 입국심사 [골드 5]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
using ll = unsigned long long;

int N, M;
vector<ll> T;

bool isValid(ll time) {
  ll cnt = 0;
  for (int i = 0; i < N; i++) {
    cnt += (time / T[i]);
  }
  if (cnt >= M) return true;
  return false;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  cin >> N >> M;
  ll left = 0, right = 0;
  for (int i = 0; i < N; i++) {
    ll ip; cin >> ip;
    T.push_back(ip);
    right = max(right, ip);
  }
  right *= M;
  sort(T.begin(), T.end());

  ll ans = right;
  while (left <= right) {
    ll mid = (left + right) / 2;
    if (isValid(mid)) {
      ans = min(ans, mid);
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  cout << ans << '\n';
}
