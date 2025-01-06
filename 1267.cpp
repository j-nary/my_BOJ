#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N; cin >> N;
  int Y = 0, M = 0, ip;
  for (int i = 0; i < N; i++) {
    cin >> ip;
    ip++;
    Y += ceil(ip/30.0) * 10;
    M += ceil(ip/60.0) * 15;
  }

  if (Y == M) cout << "Y M " << Y << '\n';
  else if (Y > M) cout << "M " << M << '\n';
  else cout << "Y " << Y << '\n';

}