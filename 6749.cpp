//BOJ_6749 Next in line[브론즈 4]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int A, B; cin >> A >> B;
  cout << B + (B - A) << '\n';
}