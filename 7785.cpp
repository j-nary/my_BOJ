#include <bits/stdc++.h>
#include <iostream>
#include <set>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N; cin >> N;

  set<string, greater<string>> s;
  for (int i = 0; i < N; i++) {
    string name, action;
    cin >> name >> action;

    if (s.count(name)) s.erase(name);
    else s.insert(name);
  }

  for (auto name: s) {
    cout << name << '\n';
  }
}