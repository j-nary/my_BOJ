//BOJ_17425 약수의 합 [골드 4]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

long long chk[1000006];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    for (int i = 1; i < 1000006; i++) {
        for (int j = i; j < 1000006; j += i) {
            chk[j] += i;
        }
    }

    for (int i = 2; i < 1000006; i++) {
        chk[i] += chk[i-1];
    }
    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        int input; cin >> input;
        cout << chk[input] << '\n';
    }
}