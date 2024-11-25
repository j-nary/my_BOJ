//BOJ_9358 순열 접기 게임 [실버 5]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool test_case() {
  int N; cin >> N;
  vector<int> v(N);
  for (int i = 0; i < N; i++) cin >> v[i];
  
  while(v.size() > 2) {
    int half = v.size() / 2;
    bool isOdd = v.size() % 2;
    for (int i = 0; i < half; i++) {
      v[i] += v[v.size() - 1];
      v.pop_back();
    }

    if (isOdd) v[v.size() - 1] *= 2;
  }

  return v[0] > v[1];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int tc; cin >> tc;
  for (int t = 1; t <= tc; t++) {
    cout << "Case #" << t << ": ";
    if (test_case()) cout << "Alice\n";
    else cout << "Bob\n";
  }
}