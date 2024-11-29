#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  long long sum = 0;
  while (1)
  {
    long long ip;
    cin >> ip;
    if (ip == -1)
      break;
    sum += ip;
  }
  cout << sum << '\n';
}