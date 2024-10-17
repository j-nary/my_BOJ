//BOJ_16675 두 개의 손 [브론즈 2]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  char ML, MR, TL, TR;
  cin >> ML >> MR >> TL >> TR;

  int flag = 0;
  if (ML == MR) {
    if (ML == 'R') {
      if (TL == 'P' || TR == 'P') flag = 1;
    } else if (ML == 'S') {
      if (TL == 'R' || TR == 'R') flag = 1;
    } else {
      if (TL == 'S' || TR == 'S') flag = 1;
    }
  }
  
  if (TL == TR) {
    if (TL == 'R') {
      if (ML == 'P' || MR == 'P') flag = -1;
    } else if (TL == 'S') {
      if (ML == 'R' || MR == 'R') flag = -1;
    } else {
      if (ML == 'S' || MR == 'S') flag = -1;
    }
  }

  if (flag == 1) cout << "TK\n";
  else if (flag == -1) cout << "MS\n";
  else cout << "?\n";
}