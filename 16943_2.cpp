//BOJ_16943 숫자 재배치 [실버 1]
//백트랙킹
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

string A, B;
int Alen, Blen;
string ans;
bool chk[10];

void backTracking(string str) {
  if (str.length() == Alen) {
    if (str < B) {
      ans = max(ans, str);
    }
    return;
  }

  for (int i = 0; i < Alen; i++) {
    if (chk[i]) continue;
    chk[i] = true;
    backTracking(str + A[i]);
    chk[i] = false;
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  cin >> A >> B;

  Alen = A.length();
  Blen = B.length();
  
  if (Alen > Blen) {
    cout << -1 << '\n';
    return 0;
  }

  sort(A.begin(), A.end(), greater<>());

  if (Alen < Blen) {
    cout << A << '\n';
    return 0;
  }

  backTracking("");
  if (ans == "" || ans[0] == '0') cout << -1 << '\n';
  else cout << ans << '\n';
}
