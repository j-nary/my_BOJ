//BOJ_31403 A+B-C [브론즈 4]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int A, B, C;
  cin >> A >> B >> C;
  cout << A + B - C << '\n';

  string str = to_string(A);
  str += to_string(B);

  cout << stoi(str) - C << '\n';
  
}