//BOJ_16943 숫자 재배치 [실버 1]
//브루투포스 [실패]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<char> V;
int Alen, Blen;

void printV() {
  for (int i = 0; i < Alen; i++) {
    cout << V[i];
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  string A, B;
  cin >> A >> B;

  Alen = A.length();
  Blen = B.length();
  
  if (Alen < Blen) {
    cout << -1 << '\n';
    return 0;
  }

  for (int i = 0; i < Alen; i++) {
    V.push_back(A[i]);
  }
  sort(V.begin(), V.end(), greater<>());

  if (Alen > Blen) {
    cout << -1 << '\n';
    return 0;
  }

  for (int i = 0; i < Alen; i++) {
    if (V[i] < B[i]) {
      printV();
      return 0;
    } else if (V[i] == B[i]) {
      continue;
    }
    for (int p = i + 1; p < Alen; p++) {
      if (V[p] <= B[i]) {
        swap(V[p], V[i]);
        break;
      }
    }
  }

  for (int i = 0; i < Alen; i++) {
    A[i] = V[i];
  }
  if (A >= B || A[0] == '0') {
    cout << -1 << '\n';
  } else {
    cout << A << '\n';
  }
}
