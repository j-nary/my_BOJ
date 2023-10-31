//BOJ_1759 암호 만들기 [골드 5]
//Backtracking 연습하기
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int L, C;
vector<char> v;
bool isVowel[20]; //모음 a,e,i,o,u

void backtracking(int depth, int vowel, int constant, string str, int idx) {
    //암호 : 최소 한 개의 모음 + 최소 두 개의 자음, 오름차순
    if (depth == L && vowel && constant >= 2) {
        cout << str << '\n';
    }

    for (int i = idx + 1; i < C; i++) {
        str.push_back(v[i]);
        backtracking(depth + 1, vowel + isVowel[i], constant + !isVowel[i], str, i);
        str.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> L >> C;
    for (int i = 0; i < C; i++) {
        char ip; cin >> ip;
        v.push_back(ip);
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < C; i++) {
        if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u') {
            isVowel[i] = true;
        }
    }
    for (int i = 0; i <= C-4; i++) {
        string tmp;
        tmp.push_back(v[i]);
        backtracking(1, isVowel[i], !isVowel[i], tmp, i);
    }
}