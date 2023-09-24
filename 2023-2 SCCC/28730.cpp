//BOJ_28730 바둑알 배치하기
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

char B[102][102];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    if (N  % 2 == 0) {
        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < N; j++) {
                cout << ".";
            }
            cout << '\n';
        }
        for (int j = 0; j < N; j++) {
            cout << "#";
        }
        cout << '\n';
    } else {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N - 1; j++) {
                cout << ".";
            }
            cout << "#\n";
        }
    }
}