// BOJ_13241 최소공배수 [실버 5]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
  ll c;
  while ( b != 0) {
    c = a % b;
    a = b;
    b = c;
  }

  return a;
}

ll lcm(ll a, ll b) {
  return b / gcd(a, b) * a;
}
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  ll a, b;
  cin >> a >> b;

  if (a < b) swap(a, b);

  cout << lcm(a, b) << '\n';
}