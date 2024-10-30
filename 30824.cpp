//BOJ_30824 피보나치 구하기 [실버 3]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
using ll = unsigned long long;

ll pibo[90];

void test_case() {
  ll K, X;
  cin >> K >> X;

  if (K == 1) {
    for (int i = 1; i < 90; i++) {
      if (pibo[i] == X) {
        cout << "YES\n";
        return;
      }
      if (pibo[i] > X) break;
    }
  } else if (K == 2) {
    for (int i = 1; i < 90; i++) {
      if (pibo[i] > X) continue;
      for (int j = i + 1; j < 90; j++) {
        if (pibo[j] > X) continue;
        ll res = pibo[i] + pibo[j];
        if (res == X) {
          cout << "YES\n";
          return;
        }
        if (res > X) break;
      }
    }
  } else if (K == 3) {
    for (int i = 1; i < 90; i++) {
      if (pibo[i] > X) continue;
      for (int j = i + 1; j < 90; j++) {
        if (pibo[j] > X) continue;
        for (int k = j + 1; k < 90; k++) {
          if (pibo[k] > X) continue;
          ll res = pibo[i] + pibo[j] + pibo[k];
          if (res == X) {
            cout << "YES\n";
            return;
          }
          if (res > X) break;
        }
      }
    }
  }
  cout << "NO\n";
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  pibo[1] = 1;
  for (int i = 2; i < 90; i++) {
    pibo[i] = pibo[i - 1] + pibo[i - 2];
  }

  int tc; cin >> tc;
  for (int t = 1; t <= tc; t++) {
    test_case();
  }
}