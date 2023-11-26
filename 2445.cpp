//BOJ_2445 별 찍기 - 8 [브론즈 3]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;
    N *= 2;
    for (int i = 1; i <= N / 2; i++) {
        for (int k = 1; k <= i; k++) {
            cout << "*";
        }
        for (int j = 0; j < N - (i * 2); j++) {
            cout << " ";
        }
        for (int k = 1; k <= i; k++) {
            cout << "*";
        }
        cout << '\n';
    }
    
    for (int i = N / 2 - 1; i >= 1; i--) {
        for (int k = 1; k <= i; k++) {
            cout << "*";
        }
        for (int j = 0; j < N - (i * 2); j++) {
            cout << " ";
        }
        for (int k = 1; k <= i; k++) {
            cout << "*";
        }
        cout << '\n';
    }

}