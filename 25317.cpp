#include <bits/stdc++.h>
#include <iostream>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N; cin >> N;

  vector<double> v;

  while (N--) {
    int Q; cin >> Q;

    if (Q == 1) {
      ll A, B; cin >> A >> B;
      v.push_back(-1 * B / A);
    } else {
      ll C; cin >> C;
      char ans = '+';
      for (int i = 0; i < v.size(); i++) {
        char ret = v[i] == C ? '0' : v[i] > C ? '+' : '-';
        if (ret == '0') {
          ans = '0';
          break;
        } else if (ret == '-') {
          ans = ans == '-' ? '+' : '-';
        }
      }
      cout << ans << '\n';
    }
  }
}