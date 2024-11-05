//BOJ_5524
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N; cin >> N;
  while (N--) {
    string str; cin >> str;
    for (int i = 0; i < str.size(); i++) {
      cout << tolower(str[i]);
    }
    cout << '\n';
  }
}