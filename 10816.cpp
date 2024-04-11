//BOJ_10816 숫자 카드 2 [실버 4]
#include <bits/stdc++.h>
#include <iostream>
#include <map>
using namespace std;

map<int, int> m;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    int ip;
    for (int i = 0; i < N; i++) {
        cin >> ip;
        m[ip]++;
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> ip;
        cout << m[ip] << ' ';
    }
    cout << '\n';
}