//BOJ_25206 너의 평점은 [실버 5]
#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  map<string, double> m = {
      {"A+", 4.5}, {"A0", 4.0},
      {"B+", 3.5}, {"B0", 3.0},
      {"C+", 2.5}, {"C0", 2.0},
      {"D+", 1.5}, {"D0", 1.0},
      {"F", 0.0}
  };
  
  string str, token;
  double sum = 0;
  double calc = 0;

  while(getline(cin, str)) {
    if (str.empty()) break;
    vector<string> tokens;
    istringstream iss(str);
    while(getline(iss, token, ' ')) tokens.push_back(token);

    if (tokens[2] == "P") continue; 

    sum += stod(tokens[1]);
    calc += stod(tokens[1]) * m[tokens[2]];
  }

  cout << fixed << setprecision(6) << calc / sum << '\n';
}