//BOJ_26168 배열 전체 탐색하기 [실버 4]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N, M;
  cin >> N >> M;

  vector<ll> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  sort(A.begin(), A.end());

  while (M--) {
    int option; cin >> option; ll K;
    switch(option) {
      case 1:
        cin >> K;
        cout << N - (lower_bound(A.begin(), A.end(), K) - A.begin()) << '\n';
        break;
      case 2:
        cin >> K;
        cout << N - (upper_bound(A.begin(), A.end(), K) - A.begin()) << '\n';
        break;
      case 3:
        ll i, j; cin >> i >> j;
        cout << upper_bound(A.begin(), A.end(), j) - lower_bound(A.begin(), A.end(), i) << '\n';
    }
  }
}