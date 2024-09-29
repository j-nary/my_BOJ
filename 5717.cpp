//BOJ_5717 상근이의 친구들 [브론즈 4]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  while(1) {
    int girl, boy;
    cin >> girl >> boy;
    if (girl == 0 && boy == 0) break;
    cout << girl + boy << '\n';
  }
}