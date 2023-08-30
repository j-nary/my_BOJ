//BOJ_2446 별 찍기 - 9 [브론즈 3]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;
    for (int i = N; i > 0; i--) {
        for (int k = 0; k < N - i; k++) {
            cout << " ";
        }
        for (int j = 0; j < i * 2 - 1; j++) {
            cout << "*";
        }
        cout << '\n';
    }
    for (int i = 2; i <= N; i++) {
        for (int k = 0; k < N - i; k++) {
            cout << " ";
        }
        for (int j = 0; j < i * 2 - 1; j++) {
            cout << "*";
        }
        cout << '\n';
 
    }
}