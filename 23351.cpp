//BOJ_23351 물 주기 [실버 3]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N, K, A, B;
  cin >> N >> K >> A >> B;

  vector<int> v;
  for (int i = 0; i < N; i++) v.push_back(K);
  
  int ans = 0;
  while(1) {
    ++ans;
    for (int i = 0; i < A; i++) v[i] += B;
    for (int i = 0; i < N; i++) --v[i];

    sort(v.begin(), v.end());
    if (v[0] <= 0) break;
  }
  cout << ans << '\n';
}

// 3 3 3 3 3 3

// Day1
// 5 5 3 3 3 3
// 4 4 2 2 2 2

// Day2
// 4 4 4 4 2 2
// 3 3 3 3 1 1

// Day3
// 3 3 3 3 3 3
// 2 2 2 2 2 2

// Day4
// 4 4 2 2 2 2
// 3 3 1 1 1 1

// Day5
// 3 3 3 3 1 1
// 3 3 3 3 0 0 !!!!!!!