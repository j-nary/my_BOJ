#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N; cin >> N;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < N - i; j++) cout << ' ';
    for (int k = 0; k < i; k++) cout << '*';
    cout << '\n';
  }

  for (int i = N - 1; i > 0; i--) {
    for (int j = 0; j < N - i; j++) cout << ' ';
    for (int k = 0; k < i; k++) cout << '*';
    cout << '\n';
  }
}