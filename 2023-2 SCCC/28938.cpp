//BOJ_28938 컨베이어 벨트
// -1 : 왼쪽으로 1미터
// 1 : 오른쪽으로 1미터
// 0 : 제자리
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        int input; cin >> input;
        sum += input;
    }
    if (sum > 0) cout << "Right" << '\n';
    else if (sum < 0) cout << "Left" << '\n';
    else cout << "Stay" << '\n';
}