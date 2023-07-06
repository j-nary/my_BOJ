//BOJ_16563 어려운 소인수분해 [골드 4]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool sosu[5000004];
vector<int> v;
void Factorization(int N) {     //소인수분해
    int tmp = 2;
    for (int i = 0; v[i] * v[i] <= N;) {
        if (N % v[i] == 0) {
            cout << v[i] << " ";
            N /= v[i];
        } else i++;
    }
    if (N != 1) cout << N << " ";
    //N이 1이 아니라면 그 자체로 루트N보다 큰 소인수가 된다!
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    sosu[1] = true;
    for (int i = 2; i * i < 5000004; i++) {
        if (sosu[i]) continue;
        for (int j = i * i; j < 5000004; j += i) {
            sosu[j] = true;
        }
    }
    for (int i = 2; i < 5000004; i++) {
        if (!sosu[i]) v.push_back(i);
    }

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int input; cin >> input;
        Factorization(input);
        cout << '\n';
    }
}