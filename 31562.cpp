//BOJ_31562 전주 듣고 노래 맞히기 [브론즈 1]
#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N, M; cin >> N >> M;
  unordered_map<string, string> m;

  cin.ignore();
  for (int i = 0; i < N; i++) {
    string input;
    getline(cin, input);

    string count = "";
    for (int i = 0; i < input.size(); i++) {
      if (input[i] >= '0' && input[i] <= '9') count.push_back(input[i]);
      else break;
    }
    int cnt = stoi(count);

    string name = input.substr(count.size() + 1, cnt);
    string code = input.substr(count.size() + 1 + name.size() + 1, 5);
    if (m.find(code) == m.end()) m[code] = name;
    else m[code] = "?";
  }

  for (int i = 0; i < M; i++) {
    string code;
    getline(cin, code);

    if (m.find(code) != m.end()) cout << m[code] << '\n';
    else cout << "!\n";
  }
}