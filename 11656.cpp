//BOJ_11656 접미사 배열 [실버 4]
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string str; cin >> str;
    vector<string> v;
    for (int i = 0; i < str.size(); i++) {
        v.push_back(str.substr(i));
    }
    sort(v.begin(), v.end());
    for (auto a : v) {
        cout << a << '\n';
    }
}