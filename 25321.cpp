#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;
const int MOD = 1e9 + 7;

int catalan(int num) {
  int res = 1;
  for (int i = 2 * num; i > 1; i--) {
    res *= (i % MOD);
    res %= MOD;
  }

  int res2 = 1;
  for (int i = num; i > 1; i--) {
    res2 *= (i % MOD);
    res2 %= MOD;
  }
  res2 *= res2 % MOD;
  res2 *= (num + 1) % MOD;
  return res / res2;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  stack<char> s;
  string ip; cin >> ip;
  int cnt = 0;
  vector<int> res;
  for (int i = 0; i < ip.size(); i++) {
    if (ip[i] == '?') s.push('?');
    else if (ip[i] == ':') {
      s.pop();
      if (!s.empty()) cnt++;
      else {
        res.push_back(cnt);
        cnt = 0;
      }
    }
  }

  int ans = 1;
  for (int i = 0; i < res.size(); i++) {
    ans *= catalan(res[i]) % MOD;
  }

  cout << ans % MOD << '\n';
} 