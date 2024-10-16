//BOJ_5073 삼각형과 세 변 [브론즈 3]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  while(1) {
    vector<int> v;
    for (int i = 0; i < 3; i++) {
      int ip; cin >> ip;
      v.push_back(ip);
    }
    sort(v.begin(), v.end());

    if (!v[0] && !v[1] && !v[2]) break;

    if (v[0] + v[1] <= v[2]) cout << "Invalid\n";
    else if (v[0] == v[1] && v[1] == v[2]) cout << "Equilateral\n";
    else if (v[0] == v[1] || v[1] == v[2]) cout << "Isosceles\n";
    else cout << "Scalene\n";
  }
}