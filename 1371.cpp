//BOJ_1371 가장 많은 글자 [브론즈 2]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int alphabet[26];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    char ip;
    while (cin >> ip) {
        if ('a' <= ip && ip <= 'z')
            alphabet[ip - 'a']++;
    }

    int m = *max_element(alphabet, alphabet + 26);
    for (int i = 0; i < 26; i++) {
        if (alphabet[i] == m)
            cout << char(i + 'a');
    }
    cout << '\n';
}