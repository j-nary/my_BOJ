#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N, M;
  cin >> N >> M;

  if (M == 1 || M == 2) cout << "NEWBIE!\n";
  else if (N >= M) cout << "OLDBIE!\n";
  else cout << "TLE!\n";
}