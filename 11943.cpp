#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << min(a + d, b + c) << '\n';
}