#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int cnt[100];
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  string str;
  cin >> str;

  for (int i = 0; i < str.length(); i++) {
    cnt[str[i] - 'a']++;
  }

  for (int i = 0; i < 26; i++) {
    cout << cnt[i] << ' ';
  }
}