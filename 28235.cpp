#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  string input;
  cin >> input;

  if (input == "SONGDO") {
    cout << "HIGHSCHOOL" << '\n';
  } else if (input == "CODE") {
    cout << "MASTER" << '\n';
  } else if (input == "2023") {
    cout << "0611" << '\n';
  } else {
    cout << "CONTEST" << '\n';
  }
}