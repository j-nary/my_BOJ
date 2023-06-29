//BOJ_11729 하노이 탑 이동 순서 [실버 1]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void hanoi(int n, int a, int b, int c) {
    if (n == 1)
        //마지막 원판의 개수가 1일 때 c로
        cout << a << " " << c << '\n';
    else {
        //a기둥의 n-1개 원판 -> b기둥으로
        hanoi(n - 1, a, c, b);
        //a기둥의 1개 원판 -> c기둥으로
        cout << a << " " << c << "\n";
        //b기둥의 n-1개의 원판 -> c기둥으로
        hanoi(n - 1, b, a, c);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N; cin >> N;
    cout << (int)pow(2, N) - 1 << '\n';
    hanoi(N, 1, 2, 3);
}