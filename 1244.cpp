//BOJ_1244 스위치 켜고 끄기 [실버 4]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int N; cin >> N;
  vector<int> swtch(N + 1);
  for (int i = 1; i <= N; i++) cin >> swtch[i];

  int M; cin >> M;
  while (M--) {
    int gender, num; cin >> gender >> num;
    swtch[num] = !swtch[num];
    if (gender == 1) {
      for (int i = num + num; i <= N; i += num) swtch[i] = !swtch[i];
    } else {
      int left = num - 1, right = num + 1;
      while(left > 0 && right <= N) {
        if (swtch[left] != swtch[right]) break;
        swtch[left] = !swtch[left];
        swtch[right] = !swtch[right];
        left--;
        right++;
      }
    }
  }

  for (int i = 1; i <= N; i++) {
    if (i != 1 && i % 20 == 1) cout << '\n';
    cout << swtch[i] << ' ';
  }
}