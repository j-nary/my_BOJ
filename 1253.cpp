//BOJ_1253 좋다 [골드 4]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N; cin >> N;
  vector<int> arr;
  for (int i = 0; i < N; i++) {
    int ip; cin >> ip;
    arr.push_back(ip);
  }

  if (N <= 2) {
    cout << 0 << '\n';
    return 0;
  }

  sort(arr.begin(), arr.end());

  int ans = 0;
  for (int i = 0; i < N; i++) {
    int left = 0, right = N - 1, sum;
    while (left < right) {
      sum = arr[left] + arr[right];
      
      if (sum == arr[i]) {
        if (left != i && right != i) {
          ans++;
          break;
        }
        
        if (left == i) left++;
        else if (right == i) right--;
      } else if (sum < arr[i]) left++;
      else right--;
    }
  }

  cout << ans << '\n';
}