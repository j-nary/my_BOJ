#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  while (1) {
    int N; cin >> N;
    if (!N) break;

    for (int i = 1; i <= N; i++) {
      for (int j = 0; j < i; j++) cout << "*";
      cout << '\n';
    }
  }
}