//BOJ_2002 추월 [실버 2]
#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, int> start;
vector<string> arrival;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N; cin >> N;

  for (int i = 1; i <= N; i++) {
    string str; cin >> str;
    start.insert({str, i});
  }

  for (int i = 1; i <= N; i++) {
    string str; cin >> str;
    arrival.push_back(str);
  }

  int cnt = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (start[arrival[i]] > start[arrival[j]]) {
        cnt++;
        break;
      }
    }
  }

  cout << cnt << '\n';
}