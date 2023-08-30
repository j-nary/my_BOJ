//BOJ_5904 Moo 게임 [골드 5]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int N;
string str = "moo";
void Moo(int depth, int length) {
    if (N <= 3) {
        cout << str[N - 1];
        return;
    }

    int nxt = length * 2 + depth + 3;
    if (N > nxt) { //찾을 수 없을 때
        Moo(depth + 1, nxt);
    } else {    //찾을 수 있을 때
        //가운데 구간
        if (N == length + 1) {
            cout << "m" << '\n';
            return;
        }
        else if (N <= length + depth + 3) {
            cout << "o" << '\n';
            return;
        }
        //S(k-1)구간
        else {
            N -= (length + depth + 3);
            Moo(1, 3);
        }
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    Moo(1, 3);
}