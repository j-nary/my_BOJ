//BOJ_1292 쉽게 푸는 문제 [브론즈 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int arr[1003];
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int A, B; cin >> A >> B;
  int k = 1;
  for (int i = 1; i <= 1000; i++) {
    for (int j = 1; j <= i; j++) {
      arr[k] = i;
      if (k > 1000) break;
      k++;
    }
  }

  int ans = 0;
  for (int i = A; i <= B; i++) {
    ans += arr[i];
  }
  cout << ans << '\n';
}