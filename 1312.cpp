#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int A, B, N;
  cin >> A >> B >> N;

  while(N--) {
    A %= B;
    A *= 10;
  }
  cout << A / B << '\n';
}