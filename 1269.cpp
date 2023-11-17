//BOJ_1269 대칭 차집합 [실버 4]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<int> A, B;

bool search(int K) {
    int s = 0, e = A.size() - 1;
    while (s <= e) {
        int m = (s + e) / 2;
        if (A[m] == K) return true;

        if (A[m] > K) e = m - 1;
        else s = m + 1;
    }
    
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int Ac, Bc, ip;
    cin >> Ac >> Bc;
    for (int i = 0; i < Ac; i++) {
        cin >> ip;
        A.push_back(ip);
    }
    sort(A.begin(), A.end());
    int cnt = 0;
    for (int i = 0; i < Bc; i++) {
        cin >> ip;
        if (search(ip)) cnt++;
    }
    cout << Ac - cnt + Bc - cnt << '\n';
}