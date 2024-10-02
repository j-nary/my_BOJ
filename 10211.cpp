//BOJ_10211 Maximum Subarray [실버 4]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int arr[1003];
void test_case() {
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) cin >> arr[i];
  int ans = arr[0];
  for (int i = 1; i < N; i++) {
    arr[i] += max(0, arr[i - 1]);
    ans = max(ans, arr[i]);
  }

  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int tc; cin >> tc;
  for (int t = 1; t <= tc; t++) {
    test_case();
  }
}