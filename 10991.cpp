#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N; cin >> N;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N - i; j++) cout << ' ';
    for (int j = 1; j <= i; j++) cout << "* ";
    cout << '\n';
  }
}