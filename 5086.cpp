#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  while (1) {
    int a, b;
    cin >> a >> b;
    if (!a && !b) break;

    if (a % b == 0) cout << "multiple\n";
    else if (b % a == 0) cout << "factor\n";
    else cout << "neither\n";
    
  }
}