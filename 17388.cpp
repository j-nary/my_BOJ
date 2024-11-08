#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  vector<pair<int, string>> v;
  int ip, sum = 0;
  cin >> ip; sum += ip; v.push_back({ip, "Soongsil"});
  cin >> ip; sum += ip; v.push_back({ip, "Korea"});
  cin >> ip; sum += ip; v.push_back({ip, "Hanyang"});

  if (sum >= 100) {
    cout << "OK\n";
    return 0;
  }

  sort(v.begin(), v.end());
  cout << v[0].second << '\n';
}