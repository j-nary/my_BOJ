//BOJ_2792 보석 상자 [실버 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
using ll = long long;
vector<ll> ruby;

ll N, M;
bool isPromising(ll mid) {
  ll cnt = 0;
  for (int i = 0; i < M; i++) {
    cnt += (ruby[i] + mid - 1) / mid;
  }
  return cnt <= N;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  cin >> N >> M;

  ll s = 1, e = 0;
  for (int i = 0; i < M; i++) {
    ll cnt; cin >> cnt;
    ruby.push_back(cnt);
    e = max(e, ruby[i]);
  }

  ll ans = 1e9 + 1;
  while (s <= e) {
    ll mid = (s + e) / 2;

    if (isPromising(mid)) {
      e = mid - 1;
      ans = min(ans, mid);
    } else s = mid + 1;
  }

  cout << ans << '\n';
}