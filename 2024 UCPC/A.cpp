#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int h, w;
  cin >> h >> w;

  int cur = (int)(min(h, w) / 2.0 * 100);
  cout << cur << '\n';
}