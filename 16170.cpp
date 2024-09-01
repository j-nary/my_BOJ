#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  time_t timer = time(NULL);
  struct tm* t = localtime(&timer);

  cout << t -> tm_year + 1900 << '\n';
  if (t -> tm_mon + 1 < 10) {
    cout << 0 << t -> tm_mon + 1 << '\n';
  } else {
    cout << t -> tm_mon + 1 << '\n';
  }
  cout << t -> tm_mday << '\n';
}