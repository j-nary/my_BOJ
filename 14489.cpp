#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int A, B, C;
  cin >> A >> B>> C;
  C *= 2;

  int sum = A + B;

  if (sum < C) {
    cout << sum << '\n';
    return 0;
  }

  cout << sum - C << '\n';
}