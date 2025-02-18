#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int M; cin >> M;
  int loc = 1;
  for (int i = 0; i < M; i++) {
    int a, b; cin >> a >> b;
    if (a == loc) loc = b;
    else if (b == loc) loc = a;
  }
  cout << loc << '\n';
}