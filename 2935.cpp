#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  string A, B;
  char op;
  cin >> A >> op >> B;

  int ASize = A.length(), BSize = B.length();

  switch(op) {
    case '+':
      if (ASize == BSize) {
        cout << "2";
        for (int i = 0; i < ASize - 1; i++) cout << "0";
      } else {
        int a = max(ASize, BSize);
        int b = min(ASize, BSize);
        for (int i = a; i > 0; i--) {
          if (i == a || i == b) cout << "1";
          else cout << "0";
        }
      }
      break;
    case '*':
      cout << "1";
      for (int i = 0; i < ASize + BSize - 2; i++) cout << "0";
  }
}