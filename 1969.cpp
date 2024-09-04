//BOJ_1969 DNA [실버 4]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;


int cnt[30][1003];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<string> dna;

    for (int i = 0; i < N; i++) {
      string str; cin >> str;
      for (int j = 0; j < str.length(); j++) {
        cnt[str[j] - 'A'][j]++;
      }
    }

    int dist = 0;

    for (int i = 0; i < M; i++) {
      int MAX = 0;
      char dna;
      for (int k = 0; k < 26; k++) {
        if (MAX < cnt[k][i]) {
          MAX = cnt[k][i];
          dna = k + 'A';
        }
        MAX = max(MAX, cnt[k][i]);
      }
      dist += (N - MAX);
      cout << dna;
    }

    cout << '\n' << dist << '\n';
}