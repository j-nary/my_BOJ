#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int N;
vector<char> v;
vector<int> R;
vector<int> L;
int count() {
  int res = 0;
  int curR = 0, curL = 0;
  for (int i = 1; i <= N; i++) {
    if (v[i] == 'R') {
      if (v[i + 1] == 'R') {
        res += (R[curR] >= R[curR]);
        curR++;
      } else {
        res += (R[curR++] >= L[curL]);
      }
    } else {
      if (v[i - 1] == 'R') {
        res += (L[curL++] >= R[curR - 1]);
      } else {
        res += (L[curL] >= L[curL - 1]);
        curL++;
      }
    }
  }
  // R 7   6      4  2
  // L   5   3  1

  // curR = 2
  // curL = 1
  return res;
}
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  cin >> N;
  R.push_back(0);
  L.push_back(0);
  for (int i = 0; i < N; i++) {
    int A;
    char D;
    cin >> A >> D;
    v.push_back(D);
    if (D == 'R') R.push_back(A);
    else L.push_back(A);
  }
  
  sort(R.begin(), R.end());
  sort(L.begin(), L.end());
  R.push_back(0);
  L.push_back(0);
  
  cout << count() << '\n';
}
//    2  3  4
// 5           1

// 7   6      4  2
//   1   3  5

// 7   6      4  2
//   5   3  1
